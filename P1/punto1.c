// Escriba un programa que llame un fork(). Antes del llamado del fork(), declare una variable de acceso (por ejemplo, x) y asígnele un valor (por ejemplo, 100). Responda las siguientes preguntas:
// ¿Cuál es el valor de la variable en el proceso hijo?
// ¿Qué sucede con la variable cuando el proceso hijo y el padre cambian el valor de x?

#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();
    int x = 100;

    if(pid == -1){
        printf("Error al crear proceso hijo");
    }
    if (pid)
    { /* padre */
        x=x+2;
        printf("Soy el padre y el valor de x es: %d \n",x);
    }
    else
    { /* hijo */
        x=x+3;
        printf("Soy el hijo y el valor de x es: %d\n",x);
    }
    printf("variable x: %d\n", x);
    return 0;
}