//
//  75SortColors.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/20.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<stack>
#include<string>
#include<sstream>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = nums.size();
        int left = 0, right = l - 1;
        for(int i = 0; i <= right;){
            if(nums[i] == 0){
                swap(nums[i], nums[left]);
                left++;
                i++;
            }
            else if(nums[i] == 2){
                swap(nums[i],nums[right]);
                right--;
            }
            else
                i++;
        }
    }
};
