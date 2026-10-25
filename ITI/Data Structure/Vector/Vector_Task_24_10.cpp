#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include <iomanip>
void print(std::vector<int> Vect)
{
    for (int item : Vect)
    {
        std::cout << item << " ";
    }
}
void print_data(const int *p, std::size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << p[i] << " ";
    }
}
int main(void)
{
    std::vector<int> v1{1, 2, 3, 4, 5};
    print(v1);
    std::cout << std::endl;
    print_data(v1.data(), v1.size());
    std::vector<int> v2{6, 7, 8, 9, 10};
    v1.swap(v2);
    std::cout << std::endl;
    print(v1);
    std::cout << std::endl;
    print_data(v2.data(), v2.size());
    std::vector<int>::iterator it;
    std::cout << std::endl;
    std::for_each(v1.crbegin(), v1.crend(), [](const int n)
                  { std::cout << n << " "; });
    it = std::find(v1.begin(), v1.end(), 8);
    std::cout << std::endl;
    std::cout << *it << std::endl;
    it = std::ranges::find(v1,6);
    std::cout << *it << std::endl;
    std::vector<int> v4{1, 2, 3, 3, 4};
    std::cout << std::count(v4.begin(), v4.end(), 3) << std::endl;
    std::cout << "the max = " << *std::max_element(v1.begin(), v1.end()) << std::endl;
    std::cout << "the min = " << *std::min_element(v1.begin(), v1.end()) << std::endl;
    int sum = std::accumulate(v1.begin(), v1.end(), 0);
    std::cout << "the sum = " << sum << std::endl;
    it = std::unique(v4.begin(), v4.end());
    v4.erase(it,v4.end());
    for(auto first{v4.begin()};first!=v4.end();first++){
        std::cout<<*first<<" ";
    }
    std::vector<int> v5{5, 9, 8, 4, 2};
    std::ranges::sort(v5);
    std::cout<<std::endl;   
    print(v5);
    std::ranges::reverse(v5);
    std::cout<<std::endl;   
    print(v5);
    std::cout<<std::endl; 
    std::vector<int> v6{5, 5,7, 5, 7, 8, 9, 4, 2};
    std::cout << "Count of 5 in v6: " << std::ranges::count(v6, 5) << std::endl;


}