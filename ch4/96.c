#include "apue.h"
int main(int argc,char *argv[]){
    struct stat buf;
    int i=0;
    char *ptr;
    for(i=1;i<argc;i++){
        printf("%s",argv[i]);
        if (lstat(argv[i],&buf)<0){
            err_ret("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode))
            ptr="regular file";
        else if (S_ISDIR(buf.st_mode))
            ptr="directory file";
        else if (S_ISBLK(buf.st_mode))
            ptr="block device";
        else if (S_ISFIFO(buf.st_mode))
            ptr="pipe file";
        else if (S_ISLNK(buf.st_mode))
            ptr="link file";
        else if (S_ISSOCK(buf.st_mode))
            ptr="socket";
        else 
            ptr="*  unkown type  *";
        printf("%s\n",ptr);
    }
    exit(0);
}