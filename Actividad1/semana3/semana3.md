# Guía Básica de PATH, Permisos SUID y Archivo /etc/passwd

# 1. PATH

El **PATH** es una variable de entorno en sistemas Unix y Linux que especifica una lista de directorios en los cuales el sistema busca los archivos ejecutables. Cuando un usuario escribe un comando en la terminal, el sistema busca el ejecutable correspondiente en los directorios listados en la variable PATH, en el orden en que aparecen.

### Visualización y Modificación del PATH

- Para ver la variable PATH, puedes usar:
	```
	echo $PATH

- Para añadir un nuevo directorio al PATH:

	```
    export PATH=$PATH:/nuevo/directorio
	```
    Este cambio es temporal y se perderá al cerrar la sesión. Para hacerlo permanente, debes agregar la línea al archivo .bashrc, .bash_profile o .zshrc, dependiendo del shell que uses.

Importancia de PATH

Tener un PATH configurado correctamente es crucial para poder ejecutar comandos sin necesidad de especificar su ruta completa. Por ejemplo, en lugar de escribir /usr/bin/ls, simplemente puedes escribir ls si /usr/bin está en tu PATH.


## 2. Permisos SUID

Los permisos SUID (Set User ID) son una característica de los sistemas Unix y Linux que permite a los usuarios ejecutar un archivo con los privilegios del propietario del archivo en lugar de con sus propios privilegios. Esto es útil para programas que necesitan acceso a recursos que normalmente solo están disponibles para el usuario root.
Visualización y Configuración de SUID

    Puedes ver si un archivo tiene el bit SUID configurado utilizando el comando ls -l:


ls -l /ruta/al/archivo

Si ves una "s" en lugar de una "x" en la parte de permisos del propietario, significa que el bit SUID está activo.

Para establecer el bit SUID en un archivo, puedes usar:

    chmod u+s /ruta/al/archivo

Riesgos de Seguridad

El uso del bit SUID puede ser peligroso si se configura incorrectamente, ya que permite a los usuarios ejecutar archivos con permisos elevados, lo que podría resultar en una brecha de seguridad si el archivo en cuestión tiene vulnerabilidades.

## 3. Archivo /etc/passwd

El archivo /etc/passwd es un archivo de texto en los sistemas Unix y Linux que contiene la información básica de las cuentas de usuario. Cada línea en este archivo representa una cuenta de usuario, y los campos están separados por dos puntos (:).
Estructura de una Línea Típica

Cada línea en el archivo /etc/passwd tiene la siguiente estructura:


nombre_usuario:x:UID:GID:información:directorio_home:shell

    nombre_usuario: Nombre de la cuenta del usuario.
    x: Este campo solía contener la contraseña del usuario, pero ahora se almacena encriptada en /etc/shadow.
    UID: Identificador de usuario (User ID).
    GID: Identificador de grupo (Group ID).
    información: Información adicional sobre el usuario, como nombre completo (opcional).
    directorio_home: Ruta al directorio home del usuario.
    shell: Shell predeterminado asignado al usuario, como /bin/bash.

Seguridad del Archivo /etc/passwd

El archivo /etc/passwd es leído por muchos programas para obtener información de los usuarios, por lo que debe ser accesible para todos los usuarios del sistema. Sin embargo, las contraseñas no se almacenan en este archivo para proteger la seguridad; en su lugar, se utiliza /etc/shadow.