//
//  69Sqrt.cpp
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
    int mySqrt(int x) {
        if(x < 2)
            return x;
        int begin  = 0, end = x;
        int lastMiddle ;
        while(begin <= end){
            int middle = (begin + end)>>1;
            if(x/middle > middle){
                begin = middle + 1;
                lastMiddle = middle;
            }
            else if (x/middle < middle){
                end = middle - 1;
            }
            else
                return middle;
        }
        return lastMiddle;
    }
};
