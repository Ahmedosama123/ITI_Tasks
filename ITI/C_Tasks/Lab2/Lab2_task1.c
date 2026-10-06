#include "stdio.h"
#include "stdlib.h"
/***************************************************************/
int main(void)
{
    int num1, num2;
    printf("Please Enter the first number:");
    scanf("%d", &num1);
    printf("second number :");
    scanf("%d", &num2);
    printf("the odd numbers is : ");
    for (int i = num1; i <= num2; i++)
    {
        if (i % 2 != 0)
        {
            printf("%d ", i);
        }
    }
    printf("\nthe even numbers is : ");
    for (int i = num1; i <= num2; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
        }
    }
}