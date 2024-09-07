## 1. Enviar mensajes con `nc` y `echo`
Puedes utilizar `nc` (netcat) para enviar mensajes a través de una red combinándolo con el comando `echo`. Este comando se usa para enviar datos a un host remoto:

echo "hola" | nc <host> <puerto>

    <host>: La dirección IP o nombre de dominio del servidor al que deseas enviar el mensaje.
    <puerto>: El puerto al que te estás conectando en el servidor remoto.

Ejemplo: enviar un mensaje a un servidor local en el puerto 8080:

echo "Hello World" | nc 127.0.0.1 8080

## 2. Conexión segura con ssl_client

ssl_client es parte de openssl y te permite conectarte a un servidor de manera segura utilizando SSL/TLS. Para establecer una conexión segura con un servidor:


openssl s_client -connect <host>:<puerto>

    <host>: El servidor al que deseas conectarte.
    <puerto>: El puerto en el servidor para la conexión segura (comúnmente el puerto 443 para HTTPS).
    -ign_eof: Este parámetro le indica al cliente que ignore el fin de archivo (EOF) y continúe enviando datos, útil en sesiones largas donde no quieres que la conexión se cierre cuando el servidor termina de enviar datos.

Por ejemplo, para conectarte a example.com en el puerto HTTPS (443):


openssl s_client -connect example.com:443

## 3. Escaneo de puertos con nmap

nmap es una herramienta poderosa para el escaneo de redes y puertos. Puedes usarla para descubrir hosts y servicios en una red. Aquí un ejemplo completo:

nmap -p- --open --min-rate 1000 -sS -n -Pn -sC -sV <host>

    -p-: Escanea todos los puertos (1-65535) en lugar de solo los más comunes.
    --open: Muestra solo los puertos que están abiertos.
    --min-rate 1000: Asegura una tasa mínima de 1000 paquetes por segundo para acelerar el escaneo.
    -sS: Realiza un escaneo TCP SYN (también conocido como escaneo furtivo, ya que no establece una conexión completa).
    -n: No realiza la resolución de nombres DNS, lo que puede hacer el escaneo más rápido.
    -Pn: Indica que no se debe hacer un ping para ver si el host está vivo, asume que está en línea.
    -sC: Ejecuta scripts básicos de detección (NSE scripts por defecto).
    -sV: Intenta detectar las versiones de los servicios en los puertos abiertos.

Ejemplo de uso:

nmap -p- --open --min-rate 1000 -sS -n -Pn -sC -sV 192.168.1.1

Este comando escaneará todos los puertos de la máquina en 192.168.1.1 y mostrará solo los abiertos.

## 4. Usar ssh con el parámetro -t

El parámetro -t en ssh es utilizado para asignar una pseudo-terminal a la sesión remota. Esto es útil cuando necesitas ejecutar comandos interactivos en la máquina remota.

ssh -t user@host 'bash -l'

    -t: Fuerza la asignación de una pseudo-terminal, lo que es necesario si vas a ejecutar un shell interactivo o un comando que requiere una terminal (como un editor de texto).

Ejemplo:

ssh -t user@192.168.1.1 'vim /etc/hosts'

Esto te permite editar el archivo /etc/hosts en la máquina remota usando vim, que requiere una interfaz interactiva.

## 5. Netcat con -nvlp

nc (netcat) puede ser utilizado para escuchar conexiones entrantes en un puerto específico. El siguiente comando escucha conexiones en un puerto dado:

nc -nvlp <puerto>

    -n: No realiza resolución de nombres DNS, utilizando directamente las direcciones IP.
    -v: Modo detallado (verbose), muestra información adicional sobre la conexión.
    -l: Coloca a nc en modo "escucha" para esperar conexiones entrantes.
    -p <puerto>: Especifica el puerto en el que deseas escuchar.

Ejemplo:

nc -nvlp 1234

Esto pondrá a nc en modo escucha en el puerto 1234, esperando cualquier conexión entrante en ese puerto.

## 6. Comprobar la suma MD5 con md5sum

md5sum se utiliza para generar una suma de verificación MD5 de un archivo. Esto se usa comúnmente para verificar la integridad de un archivo descargado:

md5sum <archivo>

    <archivo>: El archivo del cual quieres calcular la suma MD5.

Ejemplo:

md5sum ejemplo.txt

Esto imprimirá el hash MD5 de ejemplo.txt, que puede compararse con un valor esperado para verificar que el archivo no ha sido alterado.

## 7. Cortar campos con cut -d -f

cut es una herramienta que se utiliza para extraer partes específicas de una línea de texto basada en delimitadores. Por ejemplo, si tienes un archivo separado por comas, puedes extraer campos específicos usando cut:

cut -d '<delimitador>' -f<campo> <archivo>

    -d '<delimitador>': Especifica el delimitador que separa los campos en cada línea (por ejemplo, una coma , o dos puntos :).
    -f<campo>: Especifica el campo o los campos que deseas extraer.

Ejemplo:

cut -d ',' -f2 archivo.csv

Esto extraerá el segundo campo de cada línea de un archivo CSV donde los campos están separados por comas.

## 8. Crear directorios temporales con mktemp -d

mktemp -d crea un directorio temporal de forma segura. Este directorio es útil para operaciones que requieren archivos o carpetas temporales y minimiza el riesgo de colisiones con otros archivos:

mktemp -d

Este comando creará un nuevo directorio temporal en /tmp o en el directorio especificado, y devolverá la ruta completa del directorio creado.
