#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)
#define FILE_FLAG (O_CREAT|O_RDWR|O_TRUNC)


int main(void){
    int fd,fd2;
    FILE *pFile;
    int intfromfile = 0,sum = 0,max = 0,i = 0;
    char readfromfile[10];

    if((fd = open("FileSharing.txt",O_RDONLY)) < 0) return -1;
    // if ((fd = creat("FileSharing.txt", FILE_MODE)) < 0)
	// 	perror("creat error");

    // pFile = fopen( "FileSharing.txt","w" );

    // if( NULL == pFile ){
    //     printf( "open failure" );
    //     return 1;
    // }else{
    //     for(int i = 0;i < 101;i++){
    //         fprintf(pFile,"%d\n",i);
    //     }
    // }

    fd2 = dup(fd);
    srand(time(NULL));
    max = 10;

    for(i = 0;i < max;i++){
        if(i % 2 == 0){
            if(read(fd,readfromfile,10) < 10){
                printf("%c",readfromfile[1]);
                return -1;
            }else{
                intfromfile = atoi(readfromfile);
                printf("%d\n",intfromfile);
            }
            sum += intfromfile;
            printf("From fd : sum is %d after reading %d\n",sum,intfromfile);
        }else{
            if(read(fd2,readfromfile,10) < 10){
                return -1;
            }else{
                intfromfile = atoi(readfromfile);
            }
            sum += intfromfile;
            printf("From fd2 :\t\t\t sum is %d after reading %d\n",sum,intfromfile);
        }
    }

    close(fd);
    close(fd2);
    fclose(pFile);

    return 0;

}