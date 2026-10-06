#include "stdio.h"
#include "stdlib.h"
int factorial(int num)
{
    if (num == 0 || num == 1)
    {
        return 1;
    }
    else
    {
        return num * factorial(num - 1);
    }
}
int main()
{
    int n, fact;
    printf("please enter a positive number : ");
    scanf("%d", &n);
    while (n < 0)
    {
        printf("Wrong input\nplease enter a positive number : ");
        scanf("%d", &n);
    }
    fact = factorial(n);
    printf("%d! = %d", n, fact);
}