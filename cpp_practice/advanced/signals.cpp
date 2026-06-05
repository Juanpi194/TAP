#include <csignal>
#include <iostream>

void signalHandler(int signal)
{
	std::cout << "\nRecibido Ctrl+C (SIGINT)\n";

	// Liberar recursos aquí si es seguro hacerlo

	std::exit(signal);
}

int main() {
	std::signal(SIGINT, signalHandler);

	while (true)
	{
		// Tu programa
	}

	return (0);
}
