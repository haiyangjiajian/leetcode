//
//  46Permutations.cpp
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
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteHelper(nums,result,nums.begin());
        for(vector<vector<int>>::iterator a = result.begin();a!=result.end(); a++){
            for(vector<int>::iterator b = (*a).begin(); b != (*a).end(); b++){
                cout<<" "<<*b;
            }
            cout<<endl;
        }
        return result;
    }
    void permuteHelper(vector<int>& nums,vector<vector<int>> &result,vector<int>::iterator begin){
        if(begin == (nums.end()))
            result.push_back(nums);
        else{
            for(vector<int>::iterator index = begin; index != nums.end(); index++){
                swap(*index,*begin);
                permuteHelper(nums, result, begin + 1);
                swap(*index,*begin);
            }
        }
    }
};
//int main(int argc, const char * argv[]) {
//    Solution c;
//    int a[] = {1,2,3,-2};
//    vector<int> b(a, a + 4);
//    c.permute(b);
//
//}