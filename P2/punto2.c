#include<stdlib.h>
#include<stdio.h>
#include <unistd.h>
#include<fcntl.h>

int main(){

    int file_desc = open("file.txt", O_WRONLY); 
    if(file_desc < 0)
        {
            printf("Error leyendo el archivo!");   
            exit(1);             
        }
    int child = fork();

    if(child == 0){
         int sz = write(file_desc, "Modificado por el hijo\n", sizeof("Modificado por el hijo")); 
        
    }else{
         int sz = write(file_desc, "Modificado por el padre\n", sizeof("Modificado por el padre")); 
    }
    close(file_desc); 

    return 0;

}

    