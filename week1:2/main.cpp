#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    printf("argv - %s\n", argv[1]);
    
    char bf1[20] = "BUFFER-OVERFLOW";
    char bf2[20] = {0,};
    
    if(argc > 1) strcpy(bf2, argv[1]);
    bf2[32] = 'x';
    printf("bf1 - %s\n", bf1);
    printf("bf2 - %s\n", bf2);
    
    return 0;
}
