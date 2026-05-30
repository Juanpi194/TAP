#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>
#include <thread>

void	receiving_msg(int client_fd, char *buffer, int size)
{
	int	bytes;

	bytes = recv(client_fd, buffer, size, 0);
	if (bytes == -1)
		throw std::exception();
	if (bytes == 0)
		std::cout << "Client finished" << std::endl;
}

void	sending_msg(int client_fd, const std::string *msg)
{
	if (send(client_fd, msg->c_str(), msg->size(), 0) == -1)
		throw std::exception();
}

void	handle_client(int client_fd)
{
	const int		BUFFER_SIZE = 256;
	char			buffer[BUFFER_SIZE] = {};
	std::string		msg;
	
	// RECV
	receiving_msg(client_fd, buffer, BUFFER_SIZE);
	
	// SEND
	msg = "Advincula, quiero keke\n";
	sending_msg(client_fd, &msg);
	
	// CLOSE CLIENT
	close(client_fd);
	
}


int	main(void)
{
	const int			MAX_CALLS = 5;
	int					sock;
	int					client_fd;
	struct sockaddr_in	address;

	// SOCKET
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		throw std::exception();
	}

	// BIND
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	if (bind(sock, (struct sockaddr *)&address, sizeof(address)) == -1)
		throw std::exception();

	// LISTEN
	if (listen(sock, MAX_CALLS) == -1)
		throw std::exception();
		
	while (true)
	{
		// ACCEPT
		client_fd = accept(sock, nullptr, nullptr);
		if (client_fd == -1)
			throw std::exception();
		
		std::thread	client(handle_client, client_fd);
		client.detach();
	}

	// CLOSE SOCK
	close(sock);
	return (0);
}
