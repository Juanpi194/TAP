#include "Player.hpp"
#include <iostream>
#include <netinet/in.h>
#include <unistd.h>

unsigned int	Player::available_id = 0;

// Constructors ---------------------------------------------------------------
Player::Player(unsigned int fd)
{
	// char		buffer[MAX_NAME_LEN];
    // ssize_t     bytes;

	// if (send(fd, "Insert your name: ", sizeof("Insert your name: "), 0) == -1)
	// {
	// 	std::cout << "Player with fd '" << std::to_string(fd) << "' did not receive the 'insert name' message" << std::endl;
	// 	throw std::exception();
	// }
    // bytes = recv(fd, buffer, MAX_NAME_LEN, 0);
	// if (bytes == 0)
    // {
    //     std::cout << "Player with fd '" << std::to_string(fd) << "' disconnected" << std::endl;
    //     throw std::exception();
    // }
    // else if (bytes == -1)
    // {
    //     std::cout << "Player with fd '" << std::to_string(fd) << "' failed at inserting name!" << std::endl;
	// 	throw std::exception();
    // }
    // name = std::string(buffer, bytes);
	// name.erase(name.find_last_not_of("\n\r") + 1);
	name = "";
    id = available_id++;
    this->fd = fd;
}

Player::Player(unsigned int fd, const std::string& name)
{
    if (name.size() > MAX_NAME_LEN)
    {
        std::cout << "Name '" << name << "' is too long, player creation failed!" << std::endl;
        throw std::exception();
    }
    this->name = name;
    id = available_id++;
    this->fd = fd;
}

Player::Player(const Player& other)
{
    fd = other.fd;
    name = other.name;
    id = other.id;
}

// Operators ------------------------------------------------------------------
Player&	Player::operator=(const Player& other)
{
    if (this == &other)
        return (*this);
    name = other.name;
    fd = other.fd;
    id = other.id;
    return (*this);
}

bool	Player::operator==(const Player& other) const
{
    if (id == other.id)
        return (true);
    return (false);
}

// Getters --------------------------------------------------------------------
unsigned int		Player::get_fd() const
{
    return (fd);
}

const std::string&	Player::get_name() const
{
    return (name);
}

unsigned int		Player::get_id() const
{
    return (id);
}

unsigned int		Player::get_available_id()
{
    return (available_id);
}

// Setters --------------------------------------------------------------------
void	Player::set_name(const std::string& name)
{
    if (!name.empty())
        this->name = name;
}

// Utils ----------------------------------------------------------------------
bool Player::ask_name()
{
	char    buffer[MAX_NAME_LEN];
	ssize_t bytes;

	if (send(fd, "Insert your name: ", sizeof("Insert your name: "), 0) == -1)
		return (false);
	bytes = recv(fd, buffer, MAX_NAME_LEN, 0);
	if (bytes <= 0)
		return (false);
	name = std::string(buffer, bytes);
	name.erase(name.find_last_not_of("\n\r") + 1);
	return (true);
}
