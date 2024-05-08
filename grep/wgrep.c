#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char*argv[]){
    if(argc==1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    int len=strlen(argv[1]);
    if(len==0){
        exit(0);
    }

    char *line = NULL;
    size_t ln = 0;
    size_t nread;

    if(argc==2){
        while((nread = getline(&line, &ln, stdin)) != -1){
            int sz=strlen(line);
                char check[len+1];
                check[len]='\0';
                for(int i=0;i<sz;i++){
                    strncpy(check,line+i,len);
                    if(strcmp(check,argv[1])==0){
                        printf("%s",line);
                        break;
                    }
                }
        }
        exit(0);
    }
    for(int i=2;i<argc;i++){
        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
        }
        while((nread = getline(&line, &ln, fp)) != -1){
            int sz=strlen(line);
                char check[len+1];
                check[len]='\0';
                for(int i=0;i<sz;i++){
                    strncpy(check,line+i,len);
                    if(strcmp(check,argv[1])==0){
                        printf("%s",line);
                        break;
                    }
                }
        }
    }
    exit(0);
}