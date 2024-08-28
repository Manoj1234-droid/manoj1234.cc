#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
//function to demonstrate fork(),exec(),and wait()
void unix_process_management(){
    pid_t pid=fork();//create a new process
    if(pid<0){
    perror("fork failed");
    }else if (pid==0){
     //child process
     printf("child process (PID:%)executing...\n",getpid());
     execlp("ls","ls",NULL);//Replace child process with "ls" command 
     perror("execlp failed");//if execlp returns, an error ocurred 
     exit(EXIT_FAILURE);
     }else{
     //parent process
     printf("parent process(PID:%d)waiting for child to complete...\n",getpid());
     wait(NULL);//wait for the child process to complete 
     printf("child process completed.\n");
    }
}
int main(){
    unix_process_management();
    return 0;
}


