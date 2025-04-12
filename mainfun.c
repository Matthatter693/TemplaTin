#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<string.h>

void main(int argc,char*argv[])
{

//checking conditions for the correct argument input

    if(argc<2)
    {
        printf("The minimum argument count should be 3\n Run tin -h for more info\n");
        return;
    }

//adding help and version display support

    if(argv[1][0]=='-')
    {
        if(argv[1][1]=='v')
        {
            pr_info();
            return;
        }
        else if(argv[1][1]=='h')
        {
            pr_help();
            return;
        }
        else
        {
            printf("Wrong options supplied\nRun tin -h for more info");
            return;
        }
    }

// File pointers for FILE IO 

    FILE *TEMP_FILE_P=NULL; //For reading temp file
    FILE *DEST_FILE_P=NULL; //For writing into destination file
    char path[50]="../templates/";
    char pathtemp[50];
    char *p;

//An iterative condition for iterating through the arguments creating targets..

    for(int i=1;i<argc;i++)
    {
    strcpy(pathtemp,path);
    printf("pathtemp=%s\n",pathtemp);

    //Checking if the file is already present if not continues to check next argument
        if(fopen(argv[i],"r"))
        {
            printf("file %s is already present\n",argv[i]);
            continue;
        }

    //creating a file in case of its absence
        //File is created with respect to extension;
        if((p=strstr(argv[i],"."))!=NULL)
        {
            printf("reading tmp..\n");
            TEMP_FILE_P=fopen(strcat(strcat(pathtemp,p),"tmp"),"r");
            if(TEMP_FILE_P==NULL){
                printf("Template not present..\n");
            }
        }
        //incase of no extensions..
        else{
            printf("bad arguments..\n");
            return;
        }
        //safety check
        if(TEMP_FILE_P==NULL){
            printf("fp is buggy\n");
            return;
        }
        
        //Opening target with write condition and writing template contents..
        DEST_FILE_P=fopen(argv[i],"w");
        word_copy(TEMP_FILE_P,DEST_FILE_P);
        printf("The file %s is created\n",argv[i]);

        //closing File pointers
        fclose(TEMP_FILE_P);
        fclose(DEST_FILE_P);
    }

}
