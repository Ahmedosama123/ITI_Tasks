#include "stdio.h"
#include "stdlib.h"
int main(void){
    char s[]="Embedded Systems";
    int count = 0;
    for(int i = 0 ; s[i]!='\0';i++){
        count++;
    }
    printf("The length of this string = %i",count);
}