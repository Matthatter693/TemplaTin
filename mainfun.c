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
    
    //Path arrays
    char path[100]="../templates/";
    char pathtemp[100];

    //Other miscellaneous variables for storing info
    int str,flag=0;
    char ext[20];
    char *p;
    struct info temp;
    char **buf;

    //An iterative condition for iterating through the arguments creating targets..

    for(int i=1;i<argc;i++)
    {
        strcpy(pathtemp,path);

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

            /*This condition check is for multi file purposes
             * It will check the args one by one
             * when change occurs only then buf is created and allocated*/

            if((str=strcmp(ext,p))!=0)
            {
                strcpy(ext,p);

                TEMP_FILE_P=fopen(strcat(strcat(pathtemp,p),"tmp"),"r");

                if(TEMP_FILE_P==NULL){
                    printf("Template not present..\n");
                    return;
                }

                //The flag is to ensure that memory is freed in the first creation of the buffer

                if(flag==1){
                    FILE_BUF_DEALLOC(buf,temp);
                }

                //Copying file content to buffer and closing the file
                
                temp=file_info(TEMP_FILE_P);
                buf=FILE_BUF_ALLOC(temp);
                word_copy(TEMP_FILE_P,buf,temp);
                flag=1;
                fclose(TEMP_FILE_P);
            }
        }

        //incase of no extensions..
        else
        {
            printf("Add valid extensions to the files.\n");
            return;
        }

        //Opening target with write condition and writing template contents..

        DEST_FILE_P=fopen(argv[i],"w");
        word_write(DEST_FILE_P,buf,temp);
        printf("The file %s is created\n",argv[i]);
        
        //closing File pointers
        fclose(DEST_FILE_P);
    }

}
