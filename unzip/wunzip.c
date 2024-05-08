#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[]){
    if(argc==1){
        printf("wunzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    for(int i=1;i<argc;i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL){
            printf("wunzip: cannot open file\n");
            exit(1);
        }
        
        while(!feof(fp)){
            int count=0;
            char c;
            fread(&count,4,1,fp);
            fread(&c,1,1,fp);
            for(int j=0;j<count;j++) printf("%c",c);
        }
        fclose(fp);
    }
    exit(0);
}