#include <stdio.h>
int length = 5;
void display_reverse(int *arr ){
    while(length >0){
        printf("%d\n",arr[--length]);
    }

}
int main(void){
    int arr[length];
    printf ("Enter Five Numbers:\n");
    for(int i = 0 ; i < length ; i++){
        scanf("%i",&arr[i]);
    }
    display_reverse(arr);
}