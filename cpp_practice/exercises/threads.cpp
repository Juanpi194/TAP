// Crea 3 threads que cada uno imprima su número del 1 al 5. Usa un mutex para que no se mezclen las impresiones.
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

void	routine(std::mutex& mtx)
{
	for (int i = 0; i < 5; i++)
	{
		std::lock_guard<std::mutex>	lock(mtx);
		std::cout << i << std::endl;
	}
}

int	main(void)
{
	std::mutex	mtx;
	std::thread t1(routine, std::ref(mtx));
	std::thread t2(routine, std::ref(mtx));
	std::thread t3(routine, std::ref(mtx));

	// for (int i = 0; i < 3; i++)
	// 	t.detach();
	// for (int i = 0; i < 3; i++)
	// 	t.join();

	t1.join();
	t2.join();
	t3.join();
	return (0);
}
