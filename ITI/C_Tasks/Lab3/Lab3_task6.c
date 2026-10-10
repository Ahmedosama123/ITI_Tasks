#include "stdio.h"
#include "stdlib.h"
int length = 10;
int maximum(int *a){
    int max = 0;
    for(int i = 0 ;i<length;i++){
        if(a[i]>max){
            max = a[i];
        }
    }
    return max;
}
int minimum(int *a){
    int min = 50000;
    for(int i = 0 ;i<length;i++){
        if(a[i]<min){
            min = a[i];
        }
    }
    return min;
}
int main(void){
    int arr[length];
    printf("enter 10 elements:\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%i", &arr[i]);
    }
    printf("The maximum number = %i\nThe minimum number = %i",maximum(arr),minimum(arr));
}