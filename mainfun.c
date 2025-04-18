#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<string.h>
#include<unistd.h>


int verbose=0;
void main(int argc,char*argv[])
{


    //arg parsing
    int c;
    int opterr=0;
    while((c=getopt(argc,argv,"ihv:"))!=-1)
    {
        switch(c)
        {
            case 'i':
                pr_info();
                break;
            case 'h':
                pr_help();
                break;
            case 'v':
                verbose=1;
                optind=optind-1;
                break;
            case '?':
                if(optopt=='v')
                    fprintf(stderr,"the -%c flag requires arguments\n",optopt);
                else
                    printf("invalid arguments are supplied\n");
                return;
            default:
                printf("Run tin -h for usage\n");
                abort();
        }
    }

    // File pointers for FILE IO 

    FILE *TEMP_FILE_P=NULL; //For reading temp file
    FILE *DEST_FILE_P=NULL; //For writing into destination file

    //Other miscellaneous variables for storing info

    int str,flag=0;
    char ext[20];
    char *p;
    struct info temp;
    char **buf;

    //Reading Path from conf file and storing it in an array..

    char path[100];
    FILE * CONF_FILE=conf_read();
    if(CONF_FILE==NULL)
    {
        return;
    }
    struct info CONF_INFO=file_info(CONF_FILE);
    char **CONF_FILE_BUF=FILE_BUF_ALLOC(CONF_INFO);
    if(CONF_FILE_BUF==NULL)
    {
        return;
    }
    word_copy(CONF_FILE,CONF_FILE_BUF,CONF_INFO);
    p=param_read(CONF_FILE_BUF,"TEMP_PATH",CONF_INFO);
    if(p==NULL)
    {
        return;
    }
    FILE_BUF_DEALLOC(CONF_FILE_BUF,CONF_INFO);
    fclose(CONF_FILE);

    /*This pathtemp is for storing the path temporarily
      within the loop as the loop encounters files with different extensions
      And found path is copied to the path variable*/

    strcpy(path,p);
    char pathtemp[100];

    //An iterative condition for iterating through the arguments creating targets..

    for(int i=optind;i<argc;i++)
    {
        strcpy(pathtemp,path);

        //Checking if the file is already present if not continues to check next argument

        if(fopen(argv[i],"r"))
        {
            fprintf(stderr,"file %s is already present\n",argv[i]);
            continue;
        }

        //Creating a file in case of its absence
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
                if(verbose==1)
                fprintf(stdout,"%s\n",pathtemp);
                if(TEMP_FILE_P==NULL)
                {
                    fprintf(stderr,"Template not present..\n");
                    return;
                }

                //The flag is to ensure that memory is freed in the first creation of the buffer

                if(flag==1)
                {
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
            fprintf(stderr,"Add valid extensions to the files.\n");
            return;
        }

        //Opening target with write condition and writing template contents..

        DEST_FILE_P=fopen(argv[i],"w");
        word_write(DEST_FILE_P,buf,temp);
        if(verbose==1)
        fprintf(stdout,"The file %s is created\n",argv[i]);

        //closing File pointers

        fclose(DEST_FILE_P);
    }

}
