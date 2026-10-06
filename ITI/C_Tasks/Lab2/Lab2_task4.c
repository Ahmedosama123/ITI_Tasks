#include "stdio.h"
#include "stdlib.h"
int main()
{
    int rows ;
    printf("enter the width by astericks: ");
    scanf("%d", &rows);
    for (int i = 1 ; i <= rows ; i++ ){
        for(int j = 0; j<=rows*2-1 ; j++ ){
            if(j>= rows-i+1 && j<= rows+i-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
}