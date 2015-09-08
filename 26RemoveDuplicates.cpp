//
//  26RemoveDuplicates.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/2.
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
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return 0;
        int last = nums[0];
        int i, j;
        for(i = 0, j = 1;j<length;){
            if(nums[j] != last){
                i = i + 1;
                nums[i] = nums[j];
                last = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};




