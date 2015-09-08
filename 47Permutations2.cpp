//
//  47Permutations2.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/4.
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permuteUniqueHelper(nums,result,nums.begin());
//        for(vector<vector<int>>::iterator a = result.begin();a!=result.end(); a++){
//            for(vector<int>::iterator b = (*a).begin(); b != (*a).end(); b++){
//                cout<<" "<<*b;
//            }
//            cout<<endl;
//        }
        return result;
    }
    void permuteUniqueHelper(vector<int>& nums,vector<vector<int>> &result,vector<int>::iterator begin){
        if(begin == (nums.end()))
            result.push_back(nums);
        else{
            unordered_map<int, bool> perm;
            for(vector<int>::iterator index = begin; index != nums.end(); index++){
                if(!perm[*index]){
                    swap(*index,*begin);
                    permuteUniqueHelper(nums, result, begin + 1);
                    swap(*index,*begin);
                    perm[*index] = true;
                }
                
            }
        }
    }
};
//int main(int argc, const char * argv[]) {
//    Solution c;
//    int a[] = {1,2,3,-2};
//    vector<int> b(a, a + 4);
//    c.permuteUnique(b);
//    
//}