#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char*argv[]){
    if(argc==1){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }
    
    char prev;
    int count=-1;
    char c;
    for(int i=1;i<argc;i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL){
            printf("wzip: cannot open file\n");
            exit(1);
        }
        while((c=fgetc(fp))!=EOF){
            if(count==-1){
                prev=c;
                count=1;
                continue;
            }
            if(prev==c) count++;
            else{
                fwrite(&count,sizeof(int),1,stdout);
                fwrite(&prev,sizeof(char),1,stdout);
                prev=c;
                count=1;
            }
        }
        fclose(fp);
    }
    if(count!=-1){
        fwrite(&count,sizeof(int),1,stdout);
        fwrite(&prev,sizeof(char),1,stdout);
    }
    exit(0);
}