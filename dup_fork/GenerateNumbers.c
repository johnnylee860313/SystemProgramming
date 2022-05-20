#include <stdio.h>



int main(){

    FILE *pFile;

    pFile = fopen( "write.txt","w" );

    if( NULL == pFile ){

        printf( "open failure" );

        return 1;

    }else{

        for(int i = 0;i < 101;i++){
            fprintf(pFile,"%d\n",i);
        }

        

    }

    fclose(pFile);

    return 0;

}