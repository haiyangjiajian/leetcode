//
//  81SearchInRotatedSortedArray2.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/5.
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
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return false;
        int start = 0, end = nums.size() - 1;
        while(start <= end){
            int middle = (start + end)/2;
            if(nums[middle] == target){
                return true;
            }
            if(nums[middle] > nums[start]){
                if(target < nums[middle] && target >= nums[start])
                    end = middle - 1;
                else
                    start = middle + 1;
                    
            }
            else if(nums[middle] < nums[start]){
                if(target > nums[middle] && target <= nums[end])
                    start = middle + 1;
                else
                    end = middle - 1;
                    
            }
                
            else
                start++;
        }
        return false;
    }
};
