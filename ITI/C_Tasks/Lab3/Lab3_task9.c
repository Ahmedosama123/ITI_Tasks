#include "stdio.h"
#include "stdlib.h"
int count = 0;
int a[32];
int* decTbin(int num){
    for(int i = 0 ; num > 0 ; i++){
        a[i]=num%2;
        num/=2;
        count++;
    }
    return a;
}
int main (void){
    int dec;
    int *ptr;
    printf("Enter a decimal numer:");
    scanf("%d",&dec);
    ptr = decTbin(dec);
    printf("the binary of %d = ",dec);
    for(int i = count-1 ; i>=0 ; i--){
        printf("%d",ptr[i]);
    }

}