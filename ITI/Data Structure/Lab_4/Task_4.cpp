#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
int main(void)
{
    std::vector<int> v{5, 4, 2, 3, 4, 1, 5, 2, 1, 3, 7, 8};
    int length = 3;
    int s = 0, f = length - 1;
    int average = 0;
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum+=v[i];
    }
    average = sum/length;
    int max_average = average;
    while (f < v.size())
    {
        f++;
        sum+=v[f];
        sum-=v[s];
        s++;
        average = sum/length;
        max_average = __max(max_average,average);
    }
    std::cout<<"max_average = "<<max_average;
}