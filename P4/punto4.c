/*Escriba un programa que llame fork() y entonces llame alguna forma de exec() para correr el programa /bin/ls. 
Intente probar todas las variaciones de la familia de funciones exec() incluyendo (en linux) execl(), execle(), 
execlp(), execv(), execvp() y execvpe().*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


static const char *path = "/bin/ls";


int execl_test(void);
int execle_test(void);

int execvp_test(void);
int execlp_test(void);
int execv_test(void);
int execvp_test(void);
int execvpe_test(void);


int main(){

    int child = fork();
    if(child == 0){
        printf("%s","Call execl");
        //int r = execl_test();
        int cle = execle_test();
 
        int clp = execlp_test();
        int cv = execv_test();
        int cvp = execvp_test();
        //int cvpe = execvpe_test();
   
        
    }else {
        wait(0);
    }
    return 0;

}
int execl_test(void){
    char *arg1 = "-lh";   
    int r= execl(path, path, arg1, NULL);

  return r;
}

int execle_test(void){

  char *arg1 = "-lh";


  int r = execl(path, path, arg1, NULL);

  return r;
}



int execlp_test(void){
  char *arg1 = "-lh";
  int r = execlp(path, path, arg1, NULL);
  return r;
}

int execv_test(void){

  char *args[] = {"-lh", NULL};
  int r = execv(path, args);
  return r;
}


int execvp_test(void){
    char *args[] = { "-lh", NULL};
    int r = execvp(path, args);
  return r;
}

int execvpe_test(void){
    char *args[] = { "-lh", NULL};
    char *env[] = { "COLUMNS=5", NULL };
    int r = execvpe(path, args, env);
  return r;
}

//Obtenido de https://linuxhint.com/exec_linux_system_call_c/



