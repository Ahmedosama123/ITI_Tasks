#include "stdio.h"
#include "stdlib.h"
int length = 5;
void copy(int *a1 , int *a2){
    while(length > 0){
        length--;
        a2[length] = a1[length];
    }
    length = 5;
}
int main(void){
    int arr1[] = {5,16,27,36,55} , arr2[length];
    copy(arr1,arr2);
    for(int i = 0 ; i < length ; i++){
        printf("%i\n",arr2[i]);
    }
}