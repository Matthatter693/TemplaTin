#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void main(int argc,char*argv[]){

    //checking for the argument semantics
    if(argc!=2){
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

    FILE *fp,*fp1;

    //file existence check
    if(fopen(argv[1],"r")){
        printf("file %s is already present\n",argv[1]);
        return;
    }

    //creating a file in case of its absence
    fp1=fopen(argv[1],"w");
    fp=fopen("templates/cpptemp","r");
    word_copy(fp,fp1);
    printf("The file %s is created\n",argv[1]);
    fclose(fp);
    fclose(fp1);

}
