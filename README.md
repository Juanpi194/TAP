# TAP

Learn cpp bases (cpp practice), then server management (tap_practice)

![Server example](images/server_screenshot.png)

ip addr
hostname -I

nc localhost 'puerto'
nc 'ip' 'puerto'


1. std::string
2. Stack and heap, pointers vs references
3. classes
4. const, constexpr, final, noexcept, virtual
5. enum and enum class
6. Try except
7. Inheritance and polimorfism
8. std::list, std::map
9. Threads and mutex
10. Sockets TCP


## STRUCTURE

### Server

+ socket
+ list of players
+ world

- Connect users
- Shutdown server
- Start monitor routine


### Player

+ Name
+ id
+ client fd
+ connected
+ current room (*)
+ list of quests
+ list of items (*)

- Disconnect
- Show info (debug)


### Quests

+ Description
+ Completed


### World

+ Name
+ list of rooms (*)


### Room

+ Name
+ list of items (*)
+ list of npcs (*)
+ list of players (*)


### Item (ABC) -> Weapons, Potions, ...

+ Name
+ Description

- Use


### NPC (ABC) -> Enemies, quest givers, ...

+ Name

- Interact


Abrir server. Iniciar monitor routine. Ejecutar main loop (aceptar clientes constantemente y crear/logear players a partir de ellos). Cada player será un hilo.
El monitor mostrará logs y cositas.
