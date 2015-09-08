//
//  27RemoveElement.cpp
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
    void swap(int * a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int removeElement(vector<int>& nums ,int val) {
        int length = nums.size();
        if(length == 0)
            return 0;
        int l = 0 ,r = nums.size() - 1;
        while(l <= r){
            if(nums[l] == val){
                while(nums[r] == val)
                    r--;
                if(r <= l)
                    break;
                else
                    swap(&nums[l],&nums[r]);
                r--;
            }
            l++;
        }
        return l;
    }
};

