//#include"/Users/johnny/Documents/SystemProgramming/apue.3e/lib/apue.h"
#include <fcntl.h>

void set_fl(int fd,int flags){ //flags are file status flags to turn on
    
    int val;

    if((val = fcntl(fd,F_GETFL,0)) < 0){
        err_sys("fcntl F_GETFL error");
    }

    val |= flags;

    if(fcntl(fd,F_GETFL,val) < 0){
        err_sys("fcntl F_SETFL error");
    }


}