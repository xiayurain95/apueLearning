#include "apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main(void){
    if (atexit(my_exit2)!=0){
        err_sys("can't registry my_exit2");
    }
    if (atexit(my_exit1)!=0){
        err_sys("can't registry my_exit1");
    }
    printf("main is down \n");
    return(0);
}

static void my_exit1(){
    printf("first exit handler\n");
}
static void my_exit2(){
    printf("second exit handler\n");
}