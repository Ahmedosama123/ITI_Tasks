#include <iostream>
void sorting(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main(void)
{
    int arr[10] = {3, 5, 1, 4, 8, 9, 10, 12, 14, 6};
    sorting(arr, 10);
    int *i = arr;
    int *j = arr + 9;
    while (i < j)
    {
        if (*i + *j == 10)
        {
            std::cout << "Pair found: " << *i << ", " << *j << std::endl;
            i++;
            j--;
        }
        else if (*i + *j < 10)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return 0;
}