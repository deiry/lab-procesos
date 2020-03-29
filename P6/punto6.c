// Haga un programa, como el del ejercicio anterior, con una breve modificación, 
// la cual consiste en usar waitpid() en lugar de wait(). ¿Cuándo podría ser waitpid() útil?
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
        printf("Hola soy el padre y este es el valor de waitpid %d: \n", waitpid(pid,0,0));
     
    }
    else
    { /* hijo */
        printf("Hola soy el hijo y este es el valor de waitpid %d: \n", waitpid(pid,0,0));
    }
    return 0;
}