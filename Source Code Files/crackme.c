// gcc crackme.c -o crackme -fno-stack-protector
// strip --strip-debug crackme

#include <stdio.h>
#include <string.h>
#include <stdint.h>

int first_check(char *input){
    int first_part[] = {'3','m','k','c','4','r','c','_', 'g','n','1','v','l','0','s'};

    char reversed[16];
    for(int i = 0; i < 15; i++){
        reversed[i] = input[14 - i];
    }
    reversed[15] = '\0';

    for(int i = 0; i < 15; i++){
        if((int)reversed[i] != first_part[i]){
            return 0;
        }
    }

    return 1;
}

int second_check(char *input){
    uint16_t second_part[] = {
        0x1368, 0x1303, 0x1306, 0x1359, 0x1343, 0x1368, 0x1343, 0x135f,
        0x1303, 0x1343, 0x1368, 0x135f, 0x1303, 0x1345, 0x1353
    };
    
    for(int i = 0; i < 15; i++){
        uint8_t original_char = (uint8_t)(input[i]);
        uint16_t xored_char = original_char ^ 0x1337;

        if(xored_char != second_part[i]){
            return 0;
        }
    }

    return 1;
}

int main() {
    char flag[64];
    printf("\nEnter flag: ");
    fflush(stdout);
    fgets(flag, sizeof(flag), stdin);

    int len = strlen(flag);
    if(flag[len - 1] == '\n') flag[len - 1] = 0, len--;

    if(strncmp(flag, "MMU{", 4) == 0 && flag[len - 1] == '}'){
        if(first_check(flag + 4) && second_check(flag + 19))
            printf("[+] Correct flag\n");
        else
            printf("[-] Wrong flag!\n");
    }
    else{
        printf("[-] Wrong flag!\n");
    }

    return 0;
}