#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<string.h>

void main(int argc,char*argv[]){

    //checking for the argument semantics
    if(argc>3){
        printf("Wrong usage:\n");
        return;
    }

    //adding help and version commands

    if(argv[1][0]=='-'){
        if(argv[1][1]=='v'){
            pr_info();
            return;
        }
    }

    FILE *fp=NULL,*fp1=NULL;

    //file existence check
    if(fopen(argv[1],"r")){
        printf("file %s is already present\n",argv[1]);
        return;
    }

    //creating a file in case of its absence
    if(strstr(argv[1],"cpp")){
        printf("reading cpptemp..\n");
        fp=fopen("../templates/cpptemp","r");
        if(fp==NULL){
            printf("Template not present..\n");
        }
    }else{
        printf("bad arguments..\n");
        return;
    }
    if(fp==NULL){
    printf("fp is buggy\n");
    return;
    }
    fp1=fopen(argv[2],"w");
    word_copy(fp,fp1);
    printf("The file %s is created\n",argv[2]);
    fclose(fp);
    fclose(fp1);

}
