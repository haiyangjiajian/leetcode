//
//  TwoSum.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/7/24.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//
//
#include <stdio.h>
#include<vector>
#include <iostream>
#include<map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator it = nums.begin();
        vector<int>::iterator jt;
        for(;it<nums.end()-1;it++){
            for( jt = it+1;jt<nums.end();jt++){
                if(*it+*jt == target){
       //             cout<<*it<<*jt<<endl;
                    break;
                }
                
            }
            if(jt<nums.end())
                break;
        }
        vector<int> result;
        //cout<<*it<<":"<<*jt<<endl;
        result.push_back((int)(it - nums.begin() + 1));
        result.push_back((int)(jt - nums.begin() + 1));
        return result;
    }
};



class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> hmap;
        map<int,int>::iterator it;
        int plusObject = -1;
        int i;
        for(i = 0;i<nums.size();i++){
            it = hmap.find(target-nums[i]);
            if(it != hmap.end()){
                plusObject = it->second+1;
                break;
            }
            hmap.insert(pair<int,int>(nums[i],i));
        }
        vector<int> result;
        //cout<<i+1<<":"<<plusObject<<endl;
        result.push_back(plusObject);
        result.push_back(i+1);
        return result;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution2 solution;
//    
//    vector<int> nums = {2,7,11,15};
//    solution.twoSum(nums,9);
//    
//}

