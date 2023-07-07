#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void fileRead()
{
    FILE* fp = fopen("./student.txt","r");
    if(fp==NULL)
    {
        perror("open file failed:");
        return;
    }
    while(1)
    {
        char ch = fgetc(fp);
        if(feof(fp))
            break;
        printf("%c",ch);
    }
    fclose(fp);
}

void fileWrite(char a[])
{
    FILE* fp = fopen("./student.txt","a");
    if(fp ==NULL)
    {
        perror("file open failed");
        return;
    }
    for(int i=0; i<strlen(a); i++)
    {
        char ch =fputc(a[i],fp);
        printf("%c",ch);
    }
    fclose(fp);
}

void fileSelect(char a[])
{
    FILE* fp = fopen("./student.txt","r");
    if(fp==NULL)
    {
        perror("open file failed:");
        return;
    }
    char name[8]="\0",score[4]="\0";
    while(!feof(fp))
    {
        fscanf(fp,"%s",name);
        fscanf(fp,"%s",score);
        if(strcmp(a,name)==0)
        {
            printf("%s\t%s",name,score);
            break;
        }
    }
    fclose(fp);
}

int main(int argc, char *argv[]) {
    int o;
    const char *optstring = "rw:s:"; // 有三个选项-abc，其中c选项后有冒号，所以后面必须有参数
    while ((o = getopt(argc, argv, optstring)) != -1) {
        switch (o) {
            case 'r':
                fileRead();
                break;
            case 'w':
                fileWrite(optarg);
                break;
            case 's':
                fileSelect(optarg);
                break;
            case '?':
                printf("error optopt: %c\n", optopt);
                printf("error opterr: %d\n", opterr);
                break;
        }
    }
    return 0;
}
