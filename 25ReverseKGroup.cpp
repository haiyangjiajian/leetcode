//
//  25ReverseKGroup.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/8/28.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <stdio.h>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode* reverseHeadK(ListNode* head, ListNode* p){
        if(head == p || head->next == p)
            return head;
        ListNode * newHead = reverseHeadK(head->next, p);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
        
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 0 || k == 1)
            return head;
        ListNode *p = head;
        int count = 0;
        while(p != nullptr ){
            count++;
            p = p->next;
        }
        if(count < k)
            return head;
        
        p = head;
        count = 0;
        while(count<k){
            count++;
            p = p->next;
        }
        
        ListNode * newHead = reverseHeadK(head, p);
        head -> next = reverseKGroup(p, k);
        return newHead;
    }
};