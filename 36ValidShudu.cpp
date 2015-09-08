//
//  36ValidShudu.cpp
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
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() == 0)
            return false;
        bool result = true;
        int y = board.size();
        int x = board[0].size();
        for(int i = 0; i< y; i++){
            bool row[10] = { false };
            bool col[10] = { false };
            bool ban[10] = { false };
            for(int j = 0; j < x;j++){
                if(board[i][j] != '.'){
                    if(!row[board[i][j] - '0'] )
                        row[board[i][j] - '0'] = true;
                    else
                        return false;
                }
                if(board[j][i] != '.'){
                    if(!col[board[j][i] - '0'] && board[j][i] != '.')
                        col[board[j][i] - '0'] = true;
                    else
                        return false;
                }
                if (board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] != '.'){
                    if (ban[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0']) return false;
                    else ban[board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '0'] = true;
                }

            }
        }
        
        return true;
    }
};