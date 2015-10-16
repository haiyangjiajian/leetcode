//
//  73SetMatrixZeroes.cpp
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
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //the first row and the first column to index other elements, so they are indexed by the two bools.
        bool first_row = false;
        bool first_col = false;
        for(int i=0; i<n; ++i)
            if(matrix[0][i] == 0)
            {
                first_row = true;
                break;
            }
        for(int i=0; i<m; ++i)
            if(matrix[i][0] == 0)
            {
                first_col = true;
                break;
            }
        //use the first row and the first column to index the rows and columns that should be zeros.
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        }
        //set zeros.
        for(int i=1; i<m; ++i)
        {
            for(int j=1; j<n; ++j)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        }
        if(first_row)
            for(int i=0; i<n; ++i)
                matrix[0][i] = 0;
        if(first_col)
            for(int i=0; i<m; ++i)
                matrix[i][0] = 0;
    }
};