#include "stdio.h"
#include "stdlib.h"
int length = 10;
int countDuplicate(int *a)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if ( j < i && a[j] == a[i])
            {
                    break;
            }
            else if (j > i &&a[i] == a[j] )
            {
                count++;
                break;
            }
        }
    }
    return count;
}
int main(void)
{
    int arr[length];
    printf("enter 10 elements:\n");
    for (int i = 0; i < length; i++)
    {
        scanf("%i", &arr[i]);
    }
    printf("The count of duplicated numbers = %i", countDuplicate(arr));
}