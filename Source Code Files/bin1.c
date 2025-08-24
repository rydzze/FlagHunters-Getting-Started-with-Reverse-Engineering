// gcc bin1.c -o bin1 -fno-stack-protector -g

#include <stdio.h>

const char *msg = "Hello, World!";

void greet(const char *name){
    printf("Hello, %s!\n", name);
}

int main(){
    char name[32];

    puts(msg);
    printf("Enter your name: ");
    scanf("%31s", name);
    greet(name);

    return 0;
}
