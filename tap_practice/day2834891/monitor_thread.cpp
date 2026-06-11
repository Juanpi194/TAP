#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <atomic>
#include <thread>
#include <mutex>
#include <list>
#include <unistd.h>

std::atomic<bool>	running = true;

static void	monitor_thread(std::list<int>& client_list, std::mutex& mtx, int sock)
{
	std::string	msg;

	while (true)
	{
		std::cin >> msg;
		if (msg == "quit")
		{
			running = false;
			break;
		}
		else if (msg == "show")
		{
			std::lock_guard<std::mutex>	lock(mtx);
			std::cout << "Showing clients" << std::endl;
			for (int client_fd: client_list)
			{
				std::cout << client_fd << std::endl;
			}
		}
	}
	std::cout << "Closing clients' fds and removing them from the list..." << std::endl;
	std::lock_guard<std::mutex>	lock(mtx);
	for (int client_fd: client_list)
	{
		send(client_fd, "Closing...\n", sizeof("Closing...\n"), 0);
		close(client_fd);
	}
	client_list.clear();
	shutdown(sock, SHUT_RDWR);
	close(sock);
}

static void	client_thread(std::list<int>& client_list, std::mutex& mtx)
{
	while (true)
	{
		// This should end when the fd is closed
	}
}

int	main(void)
{
	constexpr unsigned int	max_clients = 5;
	int						sock;
	sockaddr_in				address;
	int						client_fd;
	std::list<int>			client_list;
	std::mutex				mtx;

	std::cout << "No error checking in this program :(" << std::endl;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	bind(sock, (sockaddr *)&address, sizeof(address));
	listen(sock, max_clients);
	std::thread	monitor(monitor_thread, std::ref(client_list), std::ref(mtx), sock);
	while (running)
	{
		client_fd = accept(sock, nullptr, nullptr);
		if (client_fd == -1)
		{
			if (!running)
				break;
			continue;
		}
		std::lock_guard<std::mutex>	lock(mtx);
		std::cout << client_fd << " joined" << std::endl;
		send(client_fd, "Welcome\n", sizeof("Welcome\n"), 0);
		client_list.push_back(client_fd);
		std::thread					client(client_thread, std::ref(client_list), std::ref(mtx));
		client.detach();
	}
	monitor.join();	// We will wait for the monitor to disconnect all users, ...
	return (0);
}
