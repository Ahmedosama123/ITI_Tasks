#include "stdio.h"
#include "stdlib.h"
int length = 10;
void unique(int *a)
{
    int uni = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (i != j)
            {
                if (a[i] == a[j])
                {
                    uni = 1;
                    break;
                }
            }
        }
        if (uni == 1)
        {
            uni = 0;
            continue;
            ;
        }
        printf("%i\n", a[i]);
    }
}
int main(void)
{
    int arr[length];
    printf("Enter 10 elements:\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%i", &arr[i]);
    }
    unique(arr);
}