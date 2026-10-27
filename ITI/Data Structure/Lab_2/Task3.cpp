#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
int main(void){
    std::vector<int> v1{2,5,1,7,10};
    int k = 14;
    int max = 0;
    std::vector<int>::iterator it1;
    std::vector<int>::iterator it2;
    it1 = v1.begin();
    it2 = v1.begin();
    while(it2!=v1.end()){
        if(std::accumulate(it1,it2+1,0) <= k){
            if(max<((it2-it1)+1))
            max = (it2-it1)+1;
            it2++;
        }
        else if(std::accumulate(it1,it2+1,0) > k){
            it1++;
        }
    }
    std::cout << max;
}