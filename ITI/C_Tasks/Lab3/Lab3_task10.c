#include "stdio.h"
#include "stdlib.h"
int main(void){
    char s[]="Ahmed Osama Mohamed";
    int count = 1;
    for(int i = 0 ; s[i]!='\0';i++){
        if(s[i] == ' '){
            count++;
        }
    }
    printf("The total number of words = %i",count);
}