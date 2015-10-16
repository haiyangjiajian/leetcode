//
//  Other_ConstructBinaryTree.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/14.
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
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution {
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
        int a = pre.size();
        int b = in.size();
        if(a == 0 || b == 0 || a != b)
            return NULL;
        return constructCore(pre, 0, a - 1, in, 0 , b - 1);
    }
    struct TreeNode* constructCore(vector<int> pre, int l1, int r1, vector<int> in, int l2, int r2){
        if(l1 > r1 || l2 > r2)
            return nullptr;
        int val = pre[l1];
        int i = l2;
        while(i <= r2 && in[i] != val)
            i++;
        if(i > r2)
            return NULL;
        TreeNode* root = new TreeNode(val);
        int len = i - l2;
        root->left = constructCore(pre, l1 + 1, l1 + len, in, l2, i - 1);
        root->right = constructCore(pre, l1 + len + 1, r1, in, i + 1, r2);
        return root;
    }
};