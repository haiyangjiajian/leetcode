//
//  42TrapRainWater.cpp
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
#include<sstream>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        int result = 0;
        if(length == 0)
            return result;
        int *maxL = new int[length];
        int *maxR = new int[length];
        int max = 0;
        for(int i = 0; i < length; i++){
             maxL[i] = max;
            if(height[i] > max){
                max = height[i];
            }
        }
        max = 0;
        for(int i = length - 1; i >= 0; i--){
            maxR[i] = max;
            if(height[i] > max){
                max = height[i];
            }
        }
        for(int i = 0;i < length; i++){
            int temp = min(maxL[i], maxR[i]) - height[i];
            if(temp > 0)
                result += temp;
        }
        delete []maxL;
        delete []maxR;
        return result;
    }
};