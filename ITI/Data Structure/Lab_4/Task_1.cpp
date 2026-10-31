#include <iostream>
#include <vector>
#include <iterator>
#include <limits>
void remove_Duplicates(std::vector<int>&v1){
    int max = INT32_MIN;
    int min = INT32_MAX;
    for(int i:v1){
        if(max<i){
            max = i;
        }
        if(min > i){
            min = i;
        }
    }
    std::vector<int>v2(max-min+1);
    std::vector<int>::iterator it;
    it = v1.begin();
    for(int item : v1){
        if(v2[*it-min] == 1){
            v1.erase(it);
        }
        else{
        v2[*it-min]++;
        it++;
        }
    }
}
int main(void){
    std::vector<int>vect{2,3,5,3,8,3,5,6,7,8,56,58,54,32,54,-1,-6,-2,-1,-5};
    remove_Duplicates(vect);
    for(int item:vect){
        std::cout<<item<<" ";
    }
    return 0;
}