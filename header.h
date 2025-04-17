
#ifndef header
#define header

struct info{
    int Newline_Count;
    int Final_Count;
};

extern FILE * conf_read();
extern char * param_read(char ** FILE_BUF,char *PARAM,struct info temp);
extern void print(char **FILE_BUF,struct info);
extern void FILE_BUF_DEALLOC(char **FILE_BUF,struct info);
extern char ** FILE_BUF_ALLOC(struct info);
extern void word_copy(FILE *,char ** ,struct info);
extern void pr_info(void);
extern void pr_help(void);
extern void word_write(FILE *,char **,struct info);
extern struct info file_info(FILE *fp);
extern void word_copy1(FILE *fp,char ** FILE_BUF,int Final_Count);


#endif
