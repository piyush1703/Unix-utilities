#include<stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc<2){
        exit(0);
    }
    for(int i=1;i<argc;i++){
        FILE *fp = fopen(argv[i], "r");
        char str[1000];
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }
        while(fgets(str,sizeof(str),fp)!=NULL){
            printf("%s",str);
        }
        fclose(fp);
    }
    exit(0);
}