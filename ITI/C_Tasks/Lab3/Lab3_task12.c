#include "stdio.h"
#include "stdlib.h"
int main(void){
    char s1[] = "Hello";
    char s2[] = "Hella";
    int change = 0;
    for(int i = 0 ; s1[i]!='\0'&&s2[i]!='\0';i++){
        if(s1[i]>s2[i]){
            printf("s1 > s2");
            change = 1;
            break;
        }
        else if(s1[i]<s2[i]){
            printf("s1 < s2");
            change = 1;
            break;
        }
    }
    if(change == 0){
        printf("s1 = s1");
    }
}