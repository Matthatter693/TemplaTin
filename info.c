#include<stdio.h>

//prints info of the TemplaTin
void pr_info(void)
{
printf("TemplaTin (Template Creator Shell Utility by matthatter693)\n");
printf("Version 1.1.2\n");
printf("This is a free software, redistributable under GPL V2.0\nFor queries <pra060903.@gmail.com>\n");
}

//help function;
void pr_help(void)
{
    printf("=================================================\n");
    printf("               TemplaTin V1.1.2\n");
    printf("=================================================\n");
    printf("USAGE:tin -[Options] [Filename with Extension]\n");
    printf("Available command options\n");
    printf("=================================================\n");
    printf("tin -h : Launches this help option\n");
    printf("tin -v : Version Check\n");
    printf("tin filename.c filename.cpp...... : File Creation\n");
}
