//
//  63UniquePaths2.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/13.
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n;
        if(m > 0)
            n = obstacleGrid[0].size();
        else
            return 0;
        if(obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1])
            return 0;
        vector<int> ops(n, 0);
        ops[0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0;j < n; j++){
                if(obstacleGrid[i][j] == 1)
                    ops[j] = 0;
                else{
                    if(j == 0)
                        ops[j] = ops[j];
                    else
                        ops[j] = ops[j-1] + ops[j];
                }
                    
            }
        }
        return ops[n - 1];
    }
};
