# Permisos, Owners y Grupos

Partiremos definiendo como visualizar los permisos que tiene cada uno de estos tipos de usuarios al listar un archivo.

Tomemos esta imagen como ejemplo:

	(Ver el archivo "archivos1.png")

Desglose del Output

I) Permisos

Cada símbolo en la cadena de permisos otorga privilegios según su estado y orden. A continuación, se detalla qué significa cada uno:

	Primer carácter: Indica el tipo de archivo.
		-: Archivo regular.
		d: Directorio.
		l: Enlace simbólico.
		Otros caracteres pueden representar diferentes tipos de archivos.
	Siguientes tres caracteres: Representan los permisos del usuario propietario.
		r: Permiso de lectura.
		w: Permiso de escritura.
		x: Permiso de ejecución.
	Tres caracteres siguientes: Representan los permisos del grupo propietario.
		r: Permiso de lectura.
		w: Permiso de escritura.
		x: Permiso de ejecución.
	Últimos tres caracteres: Representan los permisos de otros usuarios (ni el propietario ni los que pertenecen al grupo).
		r: Permiso de lectura.
		w: Permiso de escritura.
		x: Permiso de ejecución.

II) Usuario

Este campo indica el usuario propietario del archivo.

III) Grupo

Este campo indica el grupo propietario del archivo.

Ejemplo sobre el archivo "semana2.md":

	(Ver el archivo "archivos2.png")

	Tipo de archivo: El primer carácter es un -, por lo tanto, es un archivo regular.
	Permisos del usuario: rwx, el usuario moreno tiene permisos de lectura, escritura y ejecución.
	Permisos del grupo: r--, los usuarios del grupo sddm solo pueden leer el archivo.
	Permisos de otros usuarios: -w-, otros usuarios también pueden leer el archivo.

# Pipes (|) en la Terminal

Las pipes son una característica de la terminal que permite encadenar comandos, de manera que la salida de un comando se convierta en la entrada de otro. Esto es útil para procesar datos en múltiples pasos sin necesidad de crear archivos temporales.
Uso Básico

La sintaxis de una pipe es simple:

comando1 | comando2

    comando1: Genera una salida.
    |: Redirige la salida de comando1 como entrada para comando2.
    comando2: Procesa la entrada recibida de comando1.

Ejemplo


ls -l | grep ".txt"

    ls -l: Lista los archivos y directorios en formato detallado.
    |: Pasa esta lista a grep.
    grep ".txt": Filtra y muestra solo los archivos que terminan en .txt.

Este comando te permite encontrar rápidamente archivos con una extensión específica dentro de un directorio.
Encadenamiento de Múltiples Comandos


Puedes encadenar múltiples comandos con pipes:


cat archivo.txt | grep "palabra" | sort | uniq

    cat archivo.txt: Muestra el contenido de archivo.txt.
    grep "palabra": Filtra las líneas que contienen "palabra".
    sort: Ordena las líneas filtradas.
    uniq: Elimina las líneas duplicadas.

Esto te permite realizar operaciones complejas de manera concisa y eficiente.

# Redirectores

Los redireccionadores son herramientas en la terminal de Linux que permiten dirigir la entrada y salida de comandos hacia y desde archivos o dispositivos. Son útiles para guardar la salida de un comando, leer la entrada de un archivo, o incluso combinar salidas de múltiples comandos.
Conceptos Clave: stdin, stdout, y stderr

	stdin (entrada estándar): Es la fuente desde la cual un programa lee su entrada. Por defecto, stdin es el teclado.

	stdout (salida estándar): Es el destino donde un programa escribe su salida. Por defecto, stdout es la pantalla (o terminal).

	stderr (error estándar): Es el destino donde un programa escribe sus mensajes de error. Por defecto, stderr también es la pantalla, pero se trata por separado de stdout para permitir una mejor gestión de errores.

Tipos de Redireccionadores
1) Redirección de Salida (> y >>)

	>: Sobrescribe el contenido de un archivo con la salida de un comando (es decir, la redirección de stdout). Si el archivo no existe, se crea uno nuevo.

ls > archivo.txt

Esto guarda la lista de archivos y directorios en archivo.txt. Si archivo.txt ya existía, su contenido se sobrescribirá.

>>: Añade la salida de un comando al final de un archivo existente, sin sobrescribir el contenido anterior.

	echo "Nuevo texto" >> archivo.txt

	Esto añade "Nuevo texto" al final del archivo archivo.txt.

2) Redirección de Entrada (<)

	<: Toma la entrada de un archivo en lugar del teclado, redirigiendo stdin.


	cat < archivo.txt

	Esto muestra el contenido de archivo.txt en la terminal, como si se hubiera escrito manualmente.

3) Redirección de Error (2>, 2>>)

	2>: Redirige los mensajes de error (stderr) a un archivo, sobrescribiéndolo si ya existe.


ls no_existe 2> errores.txt

Si intentas listar un archivo o directorio que no existe, el mensaje de error se guarda en errores.txt.

2>>: Añade los mensajes de error al final de un archivo existente, sin sobrescribir su contenido.


	ls no_existe 2>> errores.txt

4) Redirección Combinada (&> y &>>)

	&>: Redirige tanto la salida estándar (stdout) como los mensajes de error (stderr) a un archivo, sobrescribiéndolo.


comando &> salida.txt

&>>: Añade tanto la salida estándar como los mensajes de error al final de un archivo existente.

comando &>> salida.txt