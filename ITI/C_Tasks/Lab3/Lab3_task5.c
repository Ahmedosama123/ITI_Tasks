#include "stdio.h"
#include "stdlib.h"
int length = 10;
void display_frequency(int *a)
{
    int count = 1;
    int is_counted = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (j < i && a[j] == a[i])
            {
                is_counted = 1;
                break;
            }
            else if (j > i && a[i] == a[j])
            {
                count++;
            }
        }
        if (is_counted == 1)
        {
            is_counted = 0;
            continue;
        }
        printf("%i : %i times\n", a[i], count);
        count = 1;
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
    display_frequency(arr);
}