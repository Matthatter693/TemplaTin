#include<stdio.h>
#include<stdlib.h>


//print function for checking buffer data

void print(char **FILE_BUF,int Rows)
{
    int i;
    for(i=0;i<Rows;i++)
    {
        printf("%s",FILE_BUF[i]);
    }
}

//function for buffer memory deallocation

void FILE_BUF_DEALLOC(char **FILE_BUF,int Rows)
{
    int i;
    for(int i=0;i<Rows;i++)
        free(FILE_BUF[i]);
    free(FILE_BUF);
}

//function for buffer memory allocation

char ** FILE_BUF_ALLOC(int Rows,int Cols)
{
    char ** FILE_BUF;
    int i,j;
    FILE_BUF=malloc(sizeof(char *)*Rows);
    for(i=0;i<Rows;i++)
        FILE_BUF[i]=malloc(Cols+1);
    return FILE_BUF;
}

//Function for copying text from file into the buffer and to the target

void  word_copy(FILE *fp,FILE *fp1)
{

    int Reg_Count=0,Final_Count=0,Newline_Count=0,CHARBUF;

//Calculating buffer size and lines for DMA

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

    //Memory Allocation

    char **FILE_BUF = FILE_BUF_ALLOC(Newline_Count,Final_Count);

    //Copying template content into the buffer

    for(int i=0;fgets(FILE_BUF[i],Final_Count+1,fp);i++);
    rewind(fp);

    //Writing Buffer content into target

    printf("Creating the template file\n");
    for(int i=0;i<Newline_Count;i++)
    {
        fprintf(fp1,"%s",FILE_BUF[i]);
    }
    FILE_BUF_DEALLOC(FILE_BUF,Newline_Count);
}


