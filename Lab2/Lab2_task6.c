#include "stdio.h"
#include "stdlib.h"
int main(){
    int year;
    printf("please enter the year: ");
    scanf("%d",&year);
    if(year%4==0){
        if(year%100 == 0 && year%400!=0){
            printf("Not Leap");
        }
        else{
            printf("Leap");
        }
    }
    else {
        printf("Not Leap");
    }
}