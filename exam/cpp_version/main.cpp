#include <sys/socket.h>
#include <netinet/in.h>
#include <list>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <mutex>

static void	monitor(int sock, std::list<int>& l, std::mutex& mtx)
{
	std::string	command;
	std::string	msg;

	while (true)
	{
		std::cin >> command;
		if (command == "QUIT")
		{
			msg = "Server closed\n";
			std::cout << "Closing server" << std::endl;
			std::lock_guard<std::mutex>	lock(mtx);
			for (int i: l)
			{
				send(i, msg.c_str(), msg.size(), 0);
				close(i);
			}
			close(sock);
			break;
		}
		else
			std::cout << "Unknown command" << std::endl;
	}
}

static int	main_loop(int sock, std::list<int>& l, std::mutex& mtx)
{
	int				client_fd;
	std::string		msg;

	while (true)
	{
		client_fd = accept(sock, nullptr, nullptr);
		if (client_fd == -1)
			return (0);
		std::lock_guard<std::mutex>	lock(mtx);
		l.push_back(client_fd);
		msg = std::to_string(client_fd) + " joined!\n";
		for (int fd: l)
		{
			if (send(fd, msg.c_str(), msg.size(), 0) == -1)
				return (0);
		}
	}
	return (1);
}

static int	open_server(void)
{
	int				sock;
	sockaddr_in		address;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		return (-1);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	if (bind(sock, (sockaddr *)&address, sizeof(address)) == -1)
		return (-1);
	if (listen(sock, 10) == -1)
		return (-1);
	std::cout << "Server initiated" << std::endl;
	return (sock);
}

int	main(void)
{
	int				sock;
	std::list<int>	l;
	std::mutex		mtx;

	sock = open_server();
	if (sock == -1)
		return (1);
	std::thread	t(monitor, sock, std::ref(l), std::ref(mtx));
	if (!main_loop(sock, l, mtx))
	{
		std::lock_guard<std::mutex>	lock(mtx);
		std::cout << "Problem with the main loop" << std::endl;
		for (int i: l)
			close(i);
		close(sock);
		return (1);
	}
	std::lock_guard<std::mutex>	lock(mtx);
	for (int i: l)
		close(i);
	close(sock);
	return (0);
}
