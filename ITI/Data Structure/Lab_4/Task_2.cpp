#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
int main(void)
{
    std::vector<int> v{1, 2, 5, 4, 7, 8, 9,3};
    int k = 10;
    int r = 0, l = 0;
    int sum = 0;
    int min_len = v.size()+1;
    while (r < v.size())
    {
        sum+=v[r];
        while(sum >= k)
        {
            if(min_len > r-l+1){
                min_len = r-l+1;
            }
            sum = sum - v[l];
            l++;
        }
        r++;
    }
    std::cout<<"minimum_length = " << min_len;
    return 0;
}
