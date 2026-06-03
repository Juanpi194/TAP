#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

#define	MAX_USERS	10	

int	socket_init_failed(void)
{
	std::cout << "Socket init failed" << std::endl;
	return (1);
}

int	socket_binding_failed(void)
{
	std::cout << "Socket binding failed" << std::endl;
	return (1);
}

int	socket_connection_init_failed(void)
{
	std::cout << "Socket connection init failed" << std::endl;
	return (1);
}

int	client_connection_failed(void)
{
	std::cout << "Client connection failed" << std::endl;
	return (1);
}

int main(void)
{
	int	sock;
	sockaddr_in	address;
	int	client_fd;

	sock = socket(AF_INET, SOCK_STREAM, 0);	// SOCKET (Iniciar el socket)
	if (sock == -1)
		return (socket_init_failed());
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(8080);
	if (bind(sock, (sockaddr *)&address, sizeof(address)) == -1)	// BINDING (Configurar el socket)
		return (socket_binding_failed());
	if (listen(sock, MAX_USERS) == -1)	// LISTENING (Abrir conexión a clientes)
		return (socket_connection_init_failed());
	client_fd = accept(sock, nullptr, nullptr);	// ACCEPT (Aceptar clientes)
	if (client_fd == -1)
		return (client_connection_failed());
	return (0);
}
