Conclusiones finales

## SOCKET

1️⃣ domain (AF_INET)
Representa la familia de direcciones que usarás.
AF_INET significa IPv4 (Internet Protocol v4).
Otros ejemplos:
AF_INET6 → IPv6
AF_UNIX → comunicación local entre procesos en el mismo sistema

📌 Básicamente, le estás diciendo al sistema “voy a comunicarme usando direcciones IPv4”.

2️⃣ type (SOCK_STREAM)
Es el tipo de socket, que indica cómo se enviarán los datos:
SOCK_STREAM → flujo de bytes confiable (TCP).
Es como una tubería: no se pierden datos, llegan en orden.
SOCK_DGRAM → datagramas (UDP).
Cada mensaje es independiente, no hay garantía de entrega ni de orden.
SOCK_RAW → acceso a protocolos a bajo nivel (menos común para principiantes).

📌 En tu línea, estás creando un socket TCP, que es lo típico para servidores y clientes que necesitan comunicación confiable.

3️⃣ protocol (0)
Normalmente se pone 0.
Esto deja que el sistema seleccione el protocolo adecuado para la combinación de domain y type.
Ejemplo:
Para AF_INET + SOCK_STREAM, el sistema elegirá TCP automáticamente.
Para AF_INET + SOCK_DGRAM, el sistema elegirá UDP automáticamente.

📌 Solo necesitas cambiar este valor si quieres usar un protocolo específico que no sea el “por defecto” para esa combinación.


## BIND
address.sin_family = AF_INET;
Debe de ser igual al socket, usando IPv4 en este caso

address.sin_addr.s_addr = INADDR_ANY;
INADDR_ANY vale básicamente:
0.0.0.0
Acepta conexiones en cualquiera de las interfaces de red de esta máquina.

address.sin_port = htons(8080);

### El puerto
Es el número que identifica un servicio dentro de una máquina.

## LISTEN
El socket que va a aceptar conexiones, y el número de conexiones que se van a aceptar.

## ACCEPT
El socket al que vamos a hacer la conexión.

Para los otros parámetros, usamos nullptr.

El segundo parámetro es para guardar información del cliente.
¿Por qué usas nullptr?
Porque no te interesa saber quién se conecta.

accept(sock, nullptr, nullptr);

Le estás diciendo al sistema:

"Acepta la conexión, pero no me guardes información sobre el cliente."

El último parámetro es para saber cuántos bytes se escribieron al realizar la conexión, normalmente ni se mira.
