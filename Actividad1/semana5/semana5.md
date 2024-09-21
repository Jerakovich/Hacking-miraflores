# 1. Archivo `.bashrc` o `.zshrc`

Los archivos `.bashrc` o `.zshrc` son scripts que se ejecutan automáticamente al iniciar una nueva sesión en el terminal. Son útiles para personalizar el entorno de la línea de comandos.

### ¿Cómo funcionan?
- `.bashrc`: Se ejecuta para cada nueva terminal interactiva de Bash.
- `.zshrc`: Se ejecuta para cada nueva terminal interactiva de Zsh.

### Ejemplos de personalización:

### Alias personalizados
alias ll='ls -la'

alias gs='git status'

### Variables de entorno
export EDITOR='vim'

### Funciones personalizadas
extract() {
    tar -xzvf "$1"
}

Cómo aplicar los cambios:

Después de modificar el archivo .bashrc o .zshrc, debes ejecutar el siguiente comando para recargar el archivo:

source ~/.bashrc
### o si estás usando Zsh
source ~/.zshrc

# 2. Conexión a un servidor SSH con clave privada

Para conectarse a un servidor SSH usando una clave privada, sigue estos pasos:
1. Genera una clave SSH (si no tienes una):


ssh-keygen -t rsa -b 4096 -C "tu_correo@ejemplo.com"

2. Conéctate al servidor:

Si ya tienes una clave privada (~/.ssh/id_rsa), puedes usar el siguiente comando para conectarte a un servidor SSH:

ssh -i ~/.ssh/id_rsa usuario@servidor.com

Parámetros:

    -i: Especifica el archivo de la clave privada.
    usuario: Tu nombre de usuario en el servidor.
    servidor.com: La dirección del servidor al que te conectas.

# 3. Git: git log y git show
git log

Este comando muestra el historial de commits del repositorio actual.

git log

Algunos parámetros útiles:

    --oneline: Muestra cada commit en una sola línea.
    --graph: Muestra un gráfico del historial.
    --all: Muestra todos los commits de todas las ramas.

Ejemplo:

git log 

git show

Muestra los detalles de un commit específico, incluyendo los cambios realizados.

git show <commit-hash>


Ejemplo:


git show 1a2b3c4d

# 4. Git: git branch -a y git checkout
git branch -a

Este comando lista todas las ramas locales y remotas de tu repositorio Git.

bash

git branch -a

Salida típica:

bash

* main
  develop
  remotes/origin/feature-branch

git checkout

Este comando te permite cambiar de rama o restaurar archivos del historial.
Cambiar de rama:


git checkout <nombre-de-la-rama>

Crear y cambiar a una nueva rama:

git checkout -b <nueva-rama>