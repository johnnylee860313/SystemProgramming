#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

int main(void){
    pid_t pid;
    int fd;
    int intfromfile = 0,sum = 0,max = 0,i = 0;
    char readfromfile[10];

    if((fd = open("FileSharing.txt",O_RDONLY)) < 0) return -1;

    pid = fork();
    
    if(pid == -1){
        printf("Fail to fork process\n");
    }

    srand(time(NULL));

    if(pid == 0){
        max=(rand()%10)+1;
        for(i = 0;i < max;i++){
            if(read(fd,readfromfile,10) < 10){
                printf("%c",readfromfile[1]);
                return -1;
            }else{
                intfromfile = atoi(readfromfile);
                printf("%d\n",intfromfile);
            }
            sum += intfromfile;
            printf("Child Process : sum is %d after reading %d\n",sum,intfromfile);
            usleep(10);
        }
        usleep(1000);
        printf("child : last number read is %d after reading %d lines, and the sum is %d(%d)",intfromfile,max,sum,(1+intfromfile)*max/2);
    }else{
        max=(rand()%30)+1;
        for(i = 0;i < max;i++){
            if(read(fd,readfromfile,10) < 10){
                printf("%c",readfromfile[1]);
                return -1;
            }else{
                intfromfile = atoi(readfromfile);
                printf("%d\n",intfromfile);
            }
            sum += intfromfile;
            printf("Parent Process : \t\t\t sum is %d after reading %d\n",sum,intfromfile);
            usleep(10);
        }
        usleep(1000);
        printf("parent : last number read is %d after reading %d lines, and the sum is %d(%d)",intfromfile,max,sum,(1+intfromfile)*max/2);
    }
    return 0;
}