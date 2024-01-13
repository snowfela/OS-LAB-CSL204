/*    AIM: To implement system calls in Linux
            a) fork(), getpid(), exec(), wait(), exit()
            b) stat(), opendir(), readdir(), close()       */

____________________________________________________________
// a) system calls I
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
void main() {
  pid_t pid = 0;
  int status, op;
  while (1){ 
	  printf("1. getpid()   2. fork()   3. exec()   4. wait()   5. exit() \nEnter the choice: ");
	  scanf("%d", &op);
	  switch (op){
	    case 1: if(fork()== 0) exit(0); //terminate child 
              else pid = wait(NULL); //reaping parent 
              printf("Parent pid = %d\n", getpid());
              printf("Child pid = %d\n", pid);
	            break;
	    case 2: if (fork() == 0)    //child
                printf("Child Process\n");
              else { //parent
                printf("Parent process\n");
                wait(NULL);}
	            break;
            case 3: printf("Executing 'ls' command: ");
              execlp("/bin/ls", "ls", "-l", NULL);
              perror("In exec(): ");
              break;
            case 4: if (fork() == 0) {   //child
                printf("Child Process\n");
                sleep(10);
              }
              else {   //parent
                printf("Parent process\n");
                wait(NULL);
                printf("Process ended with exit(%d).\n", WEXITSTATUS(status));
              }
              break;
            case 5: exit(0);
	    default: printf("Invalid Choice\n"); break;
}}}
____________________________________________________________
// b) system calls II
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
void main() {
    DIR *d;    
    struct dirent *de;
    struct stat buf;
    int op;
    while (1){ 
	  printf("1. stat()   2. open, read & close directory   3. exit \nEnter the choice: ");
	  scanf("%d", &op);
	  switch (op){
	    case 1: stat("./file.c", &buf);
                printf("File size =  %ld\n", buf.st_size);
	            break;
	    case 2: printf("Directory names: \n");
                d=opendir(".");
                while(de=readdir(d))
                    printf("%s\n",de->d_name);
                closedir(d);
	            break;
        case 3:  exit(0);
	    default: printf("Invalid Choice\n"); break;
}}}
