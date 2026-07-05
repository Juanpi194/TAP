#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

int	main(void)
{
	try
	{
		std::ifstream file("default_world.json");
		if (!file.is_open())
			throw std::runtime_error("Could not open file");
		json data = json::parse(file);
		std::string desc = data.value("description", "No description");	// Looking for first value. If it doesn't exist, 'No description' will be set as the returned string.
		std::cout << desc << std::endl;
	}
	catch (const json::parse_error& e)
	{
		std::cout << "JSON parse error: " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}