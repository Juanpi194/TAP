#include <sys/socket.h>	// Socket
#include <netinet/in.h>	// bind
#include <iostream>
#include <unistd.h>	// Close

int	main(void)
{
	int	sock;

	// SOCKET -----------------------------------------------------------------
	sock = socket(AF_INET, SOCK_STREAM, 0);
	// Puede fallar, hay que comprobarlo
	if (sock == -1)
	{
		std::cout << "Socket creation failed" << std::endl;
		return (1);
	}

	// BIND -------------------------------------------------------------------
	struct sockaddr_in address;
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);

	if (bind(sock, (struct sockaddr*)&address, sizeof(address)) == -1)
	{
		std::cout << "Bind failed" << std::endl;
		return (1);
	}
	// Bind suele fallar (El puerto está ya en uso por otro programa, ...)

	// LISTEN -----------------------------------------------------------------
	if (listen(sock, 5) == -1)
	{
		std::cout << "Listen failed" << std::endl;
		return (1);
	}

	// ACCEPT -----------------------------------------------------------------
	int	client_fd;

	client_fd = accept(sock, nullptr, nullptr);
	if (client_fd == -1)
	{
		std::cout << "Accept failed" << std::endl;
		return (1);
	}

	// RECV -------------------------------------------------------------------
	char buffer[256] = {};
	int bytes = recv(client_fd, buffer, sizeof(buffer), 0);
	if (bytes == -1)
	{
		std::cout << "Recovery data failed" << std::endl;
		return (1);
	}
	if (bytes == 0)
		std::cout << "Client disconnected" << std::endl;

	// SEND -------------------------------------------------------------------
	std::string msg = "Hola!\n";
	send(client_fd, msg.c_str(), msg.size(), 0);

	// CLOSE ------------------------------------------------------------------
	close(client_fd);	// Colgamos el auricular de la conversación
	close(sock);	// Apagamos el teléfono
	// El orden importa

	return (0);
}