//
//  35SearchInsert.cpp
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
    int searchInsert(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return 0;
        int start = 0, end = nums.size() - 1;
        while(start <= end){
            int middle = (start + end)/2;
            if(nums[middle] == target)
                return middle;
            else if(nums[middle] < target)
                start = middle + 1;
            else
                end = middle - 1;
        }
        return start;
    }
};
//int main(int argc, const char * argv[]) {
//    Solution c;
//    int a[] = {1,3,5,6};
//    vector<int> b(a, a + 4);
//    cout<<c.searchInsert(b, 4)<<endl;
//    
//}
