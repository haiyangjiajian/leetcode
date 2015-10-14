//
//  61RotateRight.cpp
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

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr)
            return nullptr;
        if(k == 0)
            return head;
        ListNode *p = head, *q = head;
        int length = 1;
        while(p->next){
            length++;
            p = p->next;
        }
        k = length - k%length;
        if(k == 0)
            return head;
        p->next = head;

        for(int i = 1;i < k;i++){
            q = q->next;
        }
        head = q->next;
        q->next = NULL;
        return head;
        
        
    }
};
