// Escriba un programa usando fork().
//  El proceso hijo imprimirá "Hello"; el proceso padre imprimirá "goodbye". 
//  Usted deberá asegurar que el proceso hijo imprima en primer lugar; 
//  ¿usted podría hacer esto sin llamar wait() en el padre?
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    pid_t pid;
    pid = fork();
    if(pid == -1){
        printf("Error al crear proceso hijo");
    }
    if (pid)
    { /* padre */
        sleep(1);
        printf("goodbye\n");
     
    }
    else
    { /* hijo */
        printf("hello\n");
    }
    return 0;
}