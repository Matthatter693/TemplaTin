#include<stdio.h>
#include<stdlib.h>


//print function for checking buffer data
void print(char **FILE_BUF,int Rows){
   // printf("entering print\n");6
    int i;
    for(i=0;i<Rows;i++){
        printf("%s",FILE_BUF[i]);
    }
}

//function for buffer memory deallocation
void FILE_BUF_DEALLOC(char **FILE_BUF,int Rows){
    //printf("entering dealloc\n");
    int i;
    for(int i=0;i<Rows;i++)
        free(FILE_BUF[i]);
    free(FILE_BUF);

}

//function for buffer memory allocation

char ** FILE_BUF_ALLOC(int Rows,int Cols){

    //printf("Entering mem alloc\n");
    char ** FILE_BUF;
    int i,j;
   // printf("rows=%d col=%d\n",Rows,Cols);
    FILE_BUF=malloc(sizeof(char *)*Rows);
    for(i=0;i<Rows;i++)
        FILE_BUF[i]=malloc(Cols+1);
    return FILE_BUF;
}

// this function copies word from file into the buffer

void  word_copy(FILE *fp,FILE *fp1){
    //printf("entering copy\n");
    int Reg_Count=0,Final_Count=0,Newline_Count=0,CHARBUF;

    while((CHARBUF=fgetc(fp))!=EOF){
        Reg_Count++;
        if(CHARBUF=='\n'){
            Newline_Count++;
            if(Reg_Count>Final_Count){
                Final_Count=Reg_Count;
                Reg_Count=0;
            }
        }
    }
    
    //printf("the max line len=%d new line len=%d\n",Final_Count,Newline_Count);
    rewind(fp);
    char **FILE_BUF = FILE_BUF_ALLOC(Newline_Count,Final_Count);

    for(int i=0;fgets(FILE_BUF[i],Final_Count+1,fp);i++);
    rewind(fp);

   // print(FILE_BUF,Newline_Count);
    printf("Creating the template file\n");

    for(int i=0;i<Newline_Count;i++){
        fprintf(fp1,"%s",FILE_BUF[i]);
    }
   // FILE_BUF_DEALLOC(FILE_BUF,Newline_Count);

}


