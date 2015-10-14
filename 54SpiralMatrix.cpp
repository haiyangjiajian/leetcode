//
//  54SpiralMatrix.cpp
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        vector<int >result;
        int column;
        if(row>0){
            column = matrix[0].size();
        }
        else
            return result;
        int count = 0;
        if(row % 2 == 0)
            count = row/2;
        else
            count = row/2 + 1;
        int count1 = 0;
        if(column % 2 == 0)
            count1 = column/2;
        else
            count1 = column/2 + 1;
        for(int i = 0; i < count && i < count1; i++){
            for(int j = i; j < column - i; j++)
                result.push_back(matrix[i][j]);
            for(int j = i + 1; j < row - i; j++)
                result.push_back(matrix[j][column - i - 1 ]);
            if(!(row % 2 == 1 && i == count - 1)){
                for(int j = column - i - 2; j >=0 + i; j--)
                    result.push_back(matrix[row - i - 1][j]);
            }
            if(!((column % 2 == 1) && (column - i)  == (column /2 + 1))){
                for(int j = row - i - 2; j>= 0 + i + 1; j--)
                    result.push_back(matrix[j][i]);
            }
        }
        
        return result;
    }
};

//int main(int argc, const char * argv[]) {
//    Solution c;
//    vector<vector<int>> param;
//    vector<int> a;
//    vector<int> b;
//   // a.push_back(1);
//    a.push_back(2);
//    b.push_back(3);
//    param.push_back(a);
//    param.push_back(b);
//    vector<int> result = c.spiralOrder(param);
//    for(int i = 0; i < result.size(); i++)
//        cout<<result[i]<<endl;
//    
//}
