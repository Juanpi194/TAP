#include <iostream>
#include <string>
#include <thread>
#include <list>
#include <mutex>


void	thread_routine(std::list<int>& num_list, std::mutex& mtx)
{
	constexpr unsigned int	nums_to_add = 10;
	unsigned int			i;

	for (i = 0; i < nums_to_add; i++)
	{
		std::lock_guard<std::mutex>	lock(mtx);
		num_list.push_back(i);
	}
}

int		main(void)
{
	constexpr unsigned int	num_threads = 5;
	unsigned int			i;
	std::mutex				mtx;
	std::list<int>			num_list;
	std::list<std::thread>	thread_list;	// Use vector if you wannt to use indexes

	for (i = 0; i < num_threads; i++)
	{
		std::thread	t(thread_routine, std::ref(num_list), std::ref(mtx));
		thread_list.push_back(std::move(t));	// Cannot be copied
	}
	for (std::thread& t: thread_list)
		t.join();
	std::cout << "Final list size: " << num_list.size() << std::endl;
	return (0);
}
