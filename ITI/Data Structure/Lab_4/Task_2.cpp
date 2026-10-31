#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
int main(void)
{
    std::vector<int> v{1, 2, 5, 4, 7, 8, 9, 12};
    int k = 10;
    for (int item : v)
    {
        if (item == k)
        {
            std::cout << item << std::endl;
            return 0;
        }
    }
    std::vector<int>::iterator f;
    std::vector<int>::iterator s;
    f = v.begin();
    s = v.begin();
    int count = 0;
    int min_count = v.size()+1;
    int sum = *s;
    while (f < v.end())
    {
        while (sum >= k)
        {
            count = f - s + 1;
            min_count = __min(min_count, count);
            sum -= *s;
            s++;
            count = f - s + 1;
        }
        f++;
        sum+=*f;
    }
    for(s;s<f;s++){
        std::cout << *s << " ";
    }
    return 0;
}
