// Escriba un programa que cree un proceso hijo y entonces en el proceso hijo cierre la salida estandar (STDOUT FILENO). 
// ¿Qué pasa si el hijo llama printf() para imprimir alguna salida después de cerrar el descriptor?
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();
    if(pid == -1){
        printf("Error al crear proceso hijo");
    }
    if (pid)
    { /* padre */
        printf("Hola soy el padre\n");
     
    }
    else
    { /* hijo */
        printf("Hola soy el hijo antes de cerrar STDOUT\n");
        close(STDOUT_FILENO);
        printf("Hola soy el hijo después de cerrar STDOUT\n");
    }
    return 0;
}