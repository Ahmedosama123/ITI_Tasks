#include "stdio.h"
#include "stdlib.h"
int length = 10;
void ascending(int *a)
{
    int temp;
    for (int i = 0; i < length-1; i++)
    {
        for (int j = 0; j < length-1; j++)
        {
            if (a[j + 1] < a[j])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
int main(void)
{
    int arr[length];
    printf("enter 10 elements:\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%i", &arr[i]);
    }
    ascending(arr);
    printf("After ascending\n");
   for (int i = 0; i < length; i++)
    {
        printf("%i\n", arr[i]);
    }
}