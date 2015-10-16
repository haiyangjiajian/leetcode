//
//  74SearchA2DMatrix.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/19.
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int begin = 0, end = m * n - 1;
        while(begin <= end){
            int middle = (begin + end) >>1;
            int value = matrix[middle / n][middle % n];
            if(value == target)
                return true;
            else if(value < target)
                begin = middle + 1;
            else
                end = middle - 1;
        }
        return false;
    }
};
