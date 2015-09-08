//
//  37SolveSudo.cpp
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
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solveSudoku2(board);
    }
    bool solveSudoku2(vector<vector<char>>& board) {
        if(board.size() == 0)
            return false;
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.'){
                    for(int k = 0; k < 9; k++){
                        board[i][j] = '1' + k;
                        if(isValidSudoku(board, i,j) && solveSudoku2(board))
                            return true;
                        board[i][j] = '.';
                    }
                    return false;
                }
            }
        }
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board, int m, int n) {
        for(int i = 0 ;i < 9; i++){
            if(i != n && board[m][i] == board[m][n])
                return false;
        }
        for(int i = 0 ;i < 9; i++){
            if(i != m && board[i][n] == board[m][n])
                return false;
        }
        for(int i = (m/3) *3; i < (m/3) * 3 + 3; i++){
            for(int j = (n/3) * 3; j < (n/3) * 3 + 3; j++){
                if((i!=m || j!=n )&& board[i][j] == board[m][n])
                    return false;
            }
            
        }
        return true;
    }
};