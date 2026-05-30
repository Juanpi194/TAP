#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <unistd.h>

int	main(void)
{
	const int			NUM_CLIENTS = 10;
	int					sock;
	int					client_fd;
	struct sockaddr_in	address;
	char				buffer[256];
	int					bytes;

	// Compramos el teléfono
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		throw std::exception();
	
	// Le damos un número al teléfono
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	if (bind(sock, (sockaddr *)&address, sizeof(address)) == -1)
		throw std::exception();

	// Le damos un límite de llamadas al mismo tiempo al teléfono
	if (listen(sock, NUM_CLIENTS) == -1)
		throw std::exception();

	// Conectamos el teléfono a un cliente
	client_fd = accept(sock, nullptr, nullptr);
	if (client_fd == -1)
		throw std::exception();

	// El cliente habla por el teléfono
	std::string	msg = "Hola\n";
	if (send(client_fd, msg.c_str(), msg.size(), 0) == -1)
		throw std::exception();

	// El cliente recibe un mensaje
	bytes = recv(client_fd, buffer, 256, 0);
	if (bytes == -1)
		throw std::exception();
	else if (bytes == 0)
		std::cout << "Client finished\n" << std::endl;

	// Cerramos la conexión con el cliente y el móvil.
	close(client_fd);

	// Apagamos el móvil.
	close(sock);

	std::cout << "Client sent: " << buffer << std::endl;
	return (0);
}
