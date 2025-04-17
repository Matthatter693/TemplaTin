#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"header.h"


FILE * conf_read()
{
    //getting path variables
    char *HOME_ENV=getenv("HOME");
    char *CON_NAME="/.tinconf";
    
    //allocating DMA for path variable
    char *PATH=malloc((strlen(CON_NAME)+strlen(HOME_ENV)+1));
    if(PATH==NULL)
    {
        fprintf(stderr,"Memory can't be allocated for path\n");
        return NULL;
    }
    
    //Constructing path variable
    
    strcpy(PATH,HOME_ENV);
    strcat(PATH,CON_NAME);
    
    //Checking for the file existence
    FILE *fp =fopen(PATH,"r");
    if(fp==NULL)
    {
        fprintf(stderr,"Config file not present in path %s\n",PATH);
        free(PATH);
        return NULL;
    }
    else
    {
        fprintf(stdout,"Conf file found in %s\n",PATH);
        free(PATH);
        return fp;
    }
}

//Function to read conf file parameters

char * param_read(char ** FILE_BUF,char *PARAM,struct info temp)
{
    int i;
    char *p,*q,*path_buf,*path_buf1;

    //An iterative condition for searching through the file line by line

    for(i=0;i<temp.Newline_Count;i++)
    {
        //When found following actions are triggered

        if(p=strstr(FILE_BUF[i],PARAM))
        {
            //Allocating buffer memory for the target parameter

            path_buf=malloc(strlen(p)+1);
            if(path_buf==NULL)
            {
                fprintf(stderr,"The memory can't be path_read\n");
                return NULL;
            }

            //Copying the found line to the memory and isolating the path

            strcpy(path_buf,p);
            p=path_buf;
            while(*p!='"')
                p++;
            p++;
            strcpy(path_buf,p);
            q=path_buf+strlen(path_buf);
            while(*q!='"')
                q--;
            *q='\0';

            /*If "HOME variable is found the environment variable that's set 
             * default in the shell is used to find the home directory*/

            if(p=strstr(path_buf,"HOME"))
            {
                //Expanding 'HOME' variable to system's home variable

                while(*p!='E')
                    p++;
                p++;
                strcpy(path_buf,p);
                p=getenv("HOME");
                path_buf1=malloc(strlen(p)+strlen(path_buf));
                strcpy(path_buf1,p);
                strcat(path_buf1,path_buf);
                free(path_buf);
            }
            return path_buf1;
        }
    }

    //if searched parameter is not found
    fprintf(stderr,"The Parameter %s is not found\n",PARAM);
    return NULL;
}

