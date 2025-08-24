// gcc bin3.c -o bin3 -fno-stack-protector -g

#include <stdio.h>
#include <string.h>

int main(){
    char username[32];
    char password[128];

    printf("Enter username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;

    if(strcmp(username, "admin") == 0 && strcmp(password, "thisissuperduperultramaximallysecuresecretpassword!!!") == 0){
        printf("Access granted!\n");
    }
    else{
        printf("Access denied!\n");
    }

    return 0;
}
