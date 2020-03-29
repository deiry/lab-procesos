// Escriba ahora un programa que use wait() para esperar que el proceso hijo finalice su ejecución. 
// ¿Cuál es el valor de retorno de la función wait()?, ¿Qué pasa si usted usa la función wait en el hijo?
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
        printf("Hola soy el padre y este es el valor de wait %d: \n", wait(0));
     
    }
    else
    { /* hijo */
        printf("Hola soy el hijo y este es el valor de wait %d: \n", wait(0));
    }
    return 0;
}