//
//  31NextPermutation.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/3.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<string>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        next_permutation2(num.begin(), num.end());
    }
    template<typename type>
    bool next_permutation2(type first, type last){
        const auto rfirst = reverse_iterator<type>(last);
        const auto rlast = reverse_iterator<type>(first);
        auto pivot = next(rfirst);
        while(pivot != rlast && *pivot >= *prev(pivot)){
            pivot++;
        }
        if(pivot == rlast){
            reverse(rfirst,rlast);
            return false;
        }
        auto index = rfirst;
        while(index < pivot){
            if(*index > *pivot)
                break;
            index++;
        }
        swap(*index,*pivot);
        reverse(rfirst,pivot);
        return true;
    }
};
//int main(int argc, const char * argv[]) {
//    Solution c;
//    int a[] = {1,2,3,4};
//    vector<int> b(a, a + 4);
//    c.nextPermutation(b);
//    vector<int>::iterator d = b.begin();
//    while(d!=b.end()){
//        cout<<*d<<endl;
//        d++;
//    }
//
//}