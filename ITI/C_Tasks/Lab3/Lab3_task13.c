#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int main(void){
    char s1[6]="Ahmed";
    char s2[6];
    strcpy(s2,s1);
    printf("%s",s2);
}