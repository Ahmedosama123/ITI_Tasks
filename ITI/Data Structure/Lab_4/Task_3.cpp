#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
int main(void){
    std::vector<int>v{5,1,4,10,2,3,4,5,1};
    int f = 0;
    int s = 0;
    int sum = v[0];
    int count = 0;
    int k = 5;
    while(f<=v.size()){
        if(sum > k){
            sum-=v[s];
            s++;
        }
        if(sum < k){
            f++;
            sum+=v[f];
        }
        if(sum == k){
            count++;
            f++;
            sum +=v[f];
        }
    }
    std::cout << "the num of subarrays = "<<count;
}