#include "json.hpp"
#include <fstream>
#include <iostream>

using json = nlohmann::json;

// Generated with CLAUDE
int main(void)
{
    // Leer desde archivo
    std::ifstream file("default_world.json");
    json data = json::parse(file);

    // Acceder a valores simples
    std::string name = data["name"];
    int hp = data["stats"]["hp"];

    // Iterar sobre un array
    for (const auto& room : data["rooms"])
    {
        std::string id = room["id"];
        std::string room_name = room["name"];
        std::cout << id << ": " << room_name << std::endl;
    }

    // Comprobar si existe una clave
    if (data.contains("description"))
        std::cout << data["description"] << std::endl;

    return (0);
}
