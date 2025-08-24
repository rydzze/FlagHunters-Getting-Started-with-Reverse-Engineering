// gcc bin4.c -o bin4 -fno-stack-protector -g

#include <stdio.h>
#include <string.h>

const char flag[] = 
    "\x63\x74\x66\x5b\x15\x11\x4d\x50\x4c"
    "\x13\x7f\x58\x10\x52\x7f\x13\x4e\x43"
    "\x52\x59\x50\x54\x11\x10\x4e\x5d";

char* encrypt(const char *input){
    static char output[64];
    int i;

    for(i = 0; input[i] != '\0' && i < sizeof(output) - 1; i++){
        output[i] = input[i] ^ 0x20;
    }

    output[i] = '\0';
    return output;
}

int main(){
    char input[64];

    printf("Enter flag: ");
    scanf("%63s", input);

    if(strcmp(encrypt(input), flag) == 0){
        printf("Correct\n");
    }
    else{
        printf("Wrong\n");
    }

    return 0;
}
