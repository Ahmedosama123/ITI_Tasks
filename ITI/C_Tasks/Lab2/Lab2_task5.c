#include "stdio.h"
#include "stdlib.h"
int main()
{
    int num1, num2, prime = 0;
    printf("please enter the first number in range :");
    scanf("%d", &num1);
    printf("second number :");
    scanf("%d", &num2);
    for (int i = num1; i <= num2; i++)
    {
        for (int j = 2; j <= i / 2; j++)
        {
            if (i == 1 || i == 2)
            {
                printf("%d\n", i);
                prime = 1;
            }
            else if (i > 2)
            {
                if (i % j == 0)
                {
                    prime = 1;
                    break;
                }
            }
        }
        if (prime == 0)
        {
            printf("%d\n", i);
        }
        else{
            prime = 0;
        }
    }
}