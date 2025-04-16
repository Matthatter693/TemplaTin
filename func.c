#include<stdio.h>
#include<stdlib.h>
#include"header.h"

//print function for checking buffer data

void print(char **FILE_BUF,struct info FILE_INFO)
{
    int i;
    for(i=0;i<FILE_INFO.Newline_Count;i++)
    {
        printf("%s",FILE_BUF[i]);
    }
}

//function for buffer memory deallocation

void FILE_BUF_DEALLOC(char **FILE_BUF,struct info FILE_INFO)
{
    int i;
    for(int i=0;i<FILE_INFO.Newline_Count;i++)
        free(FILE_BUF[i]);
    free(FILE_BUF);
}

//function for buffer memory allocation

char ** FILE_BUF_ALLOC(struct info FILE_INFO)
{
    char ** FILE_BUF;
    int i;
    FILE_BUF=malloc(sizeof(char *)*FILE_INFO.Newline_Count);
    if(FILE_BUF==NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }
    for(i=0;i<FILE_INFO.Newline_Count;i++){
        FILE_BUF[i]=malloc(FILE_INFO.Final_Count+1);
        if(FILE_BUF[i]==NULL)
        {
            printf("Memory allocation failed inside\n");
            return NULL;
        }
    }
    return FILE_BUF;
}


//Function that counts the no of lines in the file for Memalloc

struct info file_info(FILE *fp)
{
    //Calculating no of lines and maximum line size

    int Reg_Count=0,Final_Count=0,Newline_Count=0,CHARBUF;
    while((CHARBUF=fgetc(fp))!=EOF)
    {
        Reg_Count++;
        if(CHARBUF=='\n')
        {
            Newline_Count++;
            if(Reg_Count>Final_Count)
            {
                Final_Count=Reg_Count;
                Reg_Count=0;
            }
        }
    } 
    rewind(fp);

    //packing info into a struct and passing it
    struct info count;
    count.Newline_Count=Newline_Count;
    count.Final_Count=Final_Count;
    return count;
}


//Function for copying text from file into the buffer and to the target

void word_copy(FILE *fp,char ** FILE_BUF,struct info temp)
{
    for(int i=0;fgets(FILE_BUF[i],temp.Final_Count+1,fp);i++);
    rewind(fp);
}

//Function that writes into the file from the buffer
void word_write(FILE * fp1,char ** FILE_BUF,struct info temp)
{
    //printf("Writing the template file\n");
    for(int i=0;i<temp.Newline_Count;i++)
    {
        fprintf(fp1,"%s",FILE_BUF[i]);
    }
    rewind(fp1);
}


