#include <iostream>
#include <list>
#include <sys/socket.h>
#include <netinet/in.h>
#include <mutex>
#include <thread>
#include <unistd.h>
#include <cstring> // Memset

void add_client(std::list<int> &client_list, int new_client, std::mutex &mtx)
{
	std::lock_guard<std::mutex> lock(mtx);
	client_list.push_back(new_client);
}

void remove_client(std::list<int> &client_list, int client_to_remove, std::mutex &mtx)
{
	std::lock_guard<std::mutex> lock(mtx);
	client_list.remove(client_to_remove);
}

// El mutex es importante por si otra función está añadiendo clientes a la lista por ejemplo
void broadcast(int sender_fd, std::list<int> &client_list, std::mutex &mtx, const std::string &msg)
{
	std::lock_guard<std::mutex> lock(mtx);
	for (int client : client_list)
	{
		if (sender_fd == client)
			continue;
		if (send(client, msg.c_str(), msg.size(), 0) == -1)
			std::cout << "Client '" << client << "' did not receive the msg" << std::endl;
	}
}

bool private_msg(int sender_fd, std::string &msg, std::list<int> &client_list, std::mutex &mtx)
{
	const std::string	content = msg.substr(5);
	const int			pos = content.find(" ");
	const int			target_fd = std::stoi(content.substr(0, pos));
	const std::string	private_msg = std::to_string(sender_fd) + ": " + content.substr(pos + 1);
	const std::string	client_not_found_msg = "Client " + std::to_string(target_fd) + " is not in the list";

	for (int client_fd: client_list)
	{
		if (client_fd == target_fd)
		{
			if (send(client_fd, private_msg.c_str(), private_msg.size(), 0) == -1)
				throw std::exception();
			return true;
		}
	}
	if (send(sender_fd, client_not_found_msg.c_str(), client_not_found_msg.size(), 0) == -1)
		throw std::exception();
	return false;
}

// Thread function
void handle_client(int client_fd, std::list<int> &client_list, std::mutex &mtx)
{
	std::string msg;
	char buffer[256] = {};
	int bytes;

	while (true)
	{
		memset(buffer, 0, sizeof(buffer));
		bytes = recv(client_fd, buffer, 256, 0);
		if (bytes == -1)
			throw std::exception();
		if (bytes == 0)
			break;
		msg = std::string(buffer, bytes);
		if (msg.find("/msg") == 0) // Empieza por /msg
			private_msg(client_fd, msg, client_list, mtx);
		else
			broadcast(client_fd, client_list, mtx, std::string(buffer, bytes));
	}
	close(client_fd);
	remove_client(client_list, client_fd, mtx);
	msg = "Client '" + std::to_string(client_fd) + "' disconnected\n";
	broadcast(client_fd, client_list, mtx, msg);
}

int main(void)
{
	std::mutex mtx;
	std::list<int> client_list;
	int sock;
	int client_fd;
	struct sockaddr_in address;
	const int MAX_CLIENTS = 5;
	std::string new_client_message;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		throw std::exception();

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	if (bind(sock, (sockaddr *)&address, sizeof(address)) == -1)
		throw std::exception();
	if (listen(sock, MAX_CLIENTS) == -1)
		throw std::exception();

	while (true)
	{
		client_fd = accept(sock, nullptr, nullptr);
		if (client_fd == -1)
			throw std::exception();
		add_client(client_list, client_fd, mtx);
		std::thread client(handle_client, client_fd, std::ref(client_list), std::ref(mtx)); // std::ref es necesario al pasarle parametros a un hilo
		client.detach();
		new_client_message = "Client " + std::to_string(client_fd) + " joined!\n"; // Todos los clientes recibirán este mensaje
		broadcast(client_fd, client_list, mtx, new_client_message);
	}
	close(sock);
	return (0);
}
