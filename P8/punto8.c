#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h>
#define SIZE 26 

char* message = "Mensaje de prueba pipe()#1"; 

  
int main() 
{ 
    int R = 0;
    int W = 1;
    char buffer[SIZE]; 
    int pi[2];
    int tambytes;

  
    if (pipe(pi) < 0){
        exit(1); 
    } 

    if(fork() == 0){

        /* Ahora escribieremos en el pipe*/
        write(pi[W], message, SIZE); 
    }else{

        tambytes = read(pi[R], buffer, SIZE); 
        printf ("Tamaño de bytes: %d\n", tambytes);
        printf("%s\n", buffer); 

    }



    return 0; 
} 