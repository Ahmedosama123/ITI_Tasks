#include "stdio.h"
#include "stdlib.h"
#include "time.h"
int main(){
    int num ,guess_num;
    srand(time(NULL));
    num = rand()%100+1;
    printf("choose number from 1 to 100: ");
    scanf("%d",&guess_num);
    if(guess_num == num){
        printf("Amazing");
    }
    else{
        printf("Fail");
    }
}