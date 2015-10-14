//
//  53MaxSubArray.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/8.
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
    int maxSubArray(vector<int>& nums) {
    	if(nums.size() == 0)
    		return 0;
        int max = 0x80000000;
        int tempMax = 0;
        for(int i = 0; i < nums.size(); i++){
        	if(tempMax >= 0){
        		tempMax += nums[i];
        	}
        	else{
        		tempMax = nums[i];
        	}
        	if(tempMax > max)
        		max = tempMax;
        }
        return max;
    }
};