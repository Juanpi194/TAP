# TAP

## FUNCTIONS AND UTILS

### Socket
Crear un socket es como comprar un telefono (todavía no tiene número asignado).
```cpp
#include <sys/socket.h>

int sock = socket(AF_INET, SOCK_STREAM, 0);
// AF_INET -> Usamos IPv4 (direcciones tipo 192.168.1.1)
// SOCK_STREAM -> TCP
// 0 -> El sistema operativo elige TCP automaticamente.
// Valor devuelto (int) -> Identificador del socket (como un fd). Puede fallar, hay que comprobarlo
```

### Bind
El número del teléfono se le asigna con 'bind'.
```cpp
#include <netinet/in.h>

struct sockaddr_in address;
address.sin_family = AF_INET;	// IPv4
address.sin_addr.s_addr = INADDR_ANY;	// La IP donde vas a escuchar. INADDR_ANY -> Acepta conexiones de cualquier interfaz de red
address.sin_port = htons(8080);	// El puerto, en este caso, el 8080. htons convierte el número al orden de bytes de la red

bind(sock, (struct sockaddr*)&address, sizeof(address));
```
Aunque tenga número, todavía no puede recibir llamadas.

### Listen
```cpp
listen(sock, 5);
// El teléfono (sock) y el número de llamadas que pueden quedar en espera.
// Si el número de llamadas está en el límite, las próximas serán rechazadas.
```

### Accept
Crear un client_fd es como un auricular de una de las llamadas que el teléfono puede recibir.
```cpp
int client_fd = accept(sock, nullptr, nullptr);
// sock -> El teléfono que va a aceptar una llamada
// addr (nullptr) -> IP del que realiza llamada
// addr_len (nullptr) -> Tamaño de la estructura de dirección.
```
Esta linea hace que el hilo principal (o el que sea) se quede bloqueado en esa linea, hasta que un cliente se conecte en este caso.

### Recv
Recibir datos.
```cpp
char buffer[256] = {};
int bytes = recv(client_fd, buffer, sizeof(buffer), 0);
// client_fd -> El auricular de la conversación
// buffer -> Donde se va a guardar la información de la conversación.
// sizeof(buffer) -> Cuantos bytes como máximo quieres leer
// flags -> 0 de momento
```

### Send
Mandar datos
```cpp
std::string msg = "Hola!\n";
send(client_fd, msg.c_str(), msg.size(), 0);
// client_fd -> El auricular que recibe la información
// msg.c_str() -> La información
// msg.size() -> Tamaño de la información que queremos pasar
// flags -> 0
```
Sabes que un mensaje ha terminado cuando recibes un salto de línea.
Es necesario implementar un bucle que acumule bytes hasta encontrar ese \n.

### Close
```cpp
#include <unistd.h>

close(client_fd);	// Colgamos el auricular de la conversación
close(sock);	// Apagamos el teléfono
```
El orden importa. Primero se cierran las conexiones de los clientes, luego el socket servidor.


### Threads
```cpp
#include <thread>

std::thread t(funcion, argumento);
t.detach(); // o t.join()
```
detach permitirá al hilo principal continuar.
join esperará a que el resto de hilos lleguen.

La flag `-pthread` es necesaria a la hora de compilar.
```bash
g++ -o server server.cpp -pthread
```

### Mutex
Igual que en c
```cpp
#include <mutex>

std::mutex	mtx;
mtx.lock();
clients.push_back(client_fd);
mtx.unlock();
```

En cpp existe un método más seguro:
```cpp
{
    std::lock_guard<std::mutex> lock(mtx); // hace lock aquí
    clients.push_back(client_fd);
} // al salir del bloque, lock se destruye y hace unlock automáticamente
```
Ahorra el unlock. Al terminar el bloque se libera.


## SERVER
Cada cliente será un hilo. El hilo principal estará en bucle esperando a nuevos clientes.
Los clientes (hilos) estarán en bucle, mandando mensajes (por ejemplo) y
solo cerrarán la conexión si "matan" el proceso (Ctrl + C / Ctrl + D)

## GUIDE
1. main.cpp
2. server_example.cpp
3. client_list.cpp
4. client_list_chat.cpp

## TCP
TCP garantiza que los datos llegan completos y en orden
Hay una conexión establecida antes de mandar datos
Los datos son un flujo continuo de bytes, no mensajes separados
