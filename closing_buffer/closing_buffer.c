/* In this exmaple,we demo that an automatically allocated buffer for buffer IO or 
    local variable for buffer IO may cause memory access error
*/
#include<stdio.h>

void write_file(FILE *fp){
    int i;
    char buffer[] = {'@'};
    char iobuf[256];
    
    setvbuf(fp,iobuf,_IOFBF,256);

    for(i = 0; i < 512;i++){
        fwrite(buffer,1,1,fp);
    }
        

} 

int main(){
    FILE *fp = fopen("./write.txt","w+");
    write_file(fp);
    fclose(fp);
    return 0;
}