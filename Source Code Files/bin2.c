// gcc bin2.c -o bin2 -fno-stack-protector -g

#include <stdio.h>

void func1(){
    void *rsp, *rbp;
    __asm__("mov %%rsp, %0" : "=r"(rsp));
    __asm__("mov %%rbp, %0" : "=r"(rbp));

    printf("RSP in func1: %p\nRBP in func1: %p\n", rsp, rbp);
}

void func2(){
    void *rsp, *rbp;
    __asm__("mov %%rsp, %0" : "=r"(rsp));
    __asm__("mov %%rbp, %0" : "=r"(rbp));

    printf("RSP in func2: %p\nRBP in func2: %p\n", rsp, rbp);
    func1();
}

int main(){
    void *rsp, *rbp;
    __asm__("mov %%rsp, %0" : "=r"(rsp));
    __asm__("mov %%rbp, %0" : "=r"(rbp));

    puts("\nCase 1\n------\n");
    printf("RSP in main : %p\nRBP in main : %p\n", rsp, rbp);
    func1();

    puts("\nCase 2\n------\n");
    printf("RSP in main : %p\nRBP in main : %p\n", rsp, rbp);
    func2();

    return 0;
}
