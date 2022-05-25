#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>

int main(int argc,char *argv[]){
    int numBytes,flags,fd,j;
    int useLseek;

    if(argc < 3 || strcmp(argv[1],"--help") == 0){
        fprintf(stderr,"%s file num-byets [x]\n 'x' means use lseek instead of O_APPEND\n",argv[0]);
        exit(-1);
    }

    //Use lseek if third argument is defined,otherwise,O_APPEND is used
    useLseek = argc > 3;
    flags = useLseek ? 0 : O_APPEND;
    
    //Number of bytes written into file
    numBytes = atoi(argv[2]);

    //Create an empty file to write in with flags defined above
    fd = open(argv[1],O_RDWR | O_CREAT | flags,S_IRUSR | S_IWUSR);
    if(fd == -1){
        fprintf(stderr,"open file error\n");
        exit(-1);
    }

    for(j = 0;j < numBytes;j++){
        if(useLseek){
            if(lseek(fd,0,SEEK_END) == -1){
                fprintf(stderr,"lseek error\n");
                exit(-1);
            }
        }
        if(write(fd,"x",1) != 1){
            fprintf(stderr,"write error\n");
            exit(-1);
        }
    }

    exit(0);

}