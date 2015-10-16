//
//  147InsertionSortList.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/9/20.
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
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode dummy(0x80000000);
        dummy.next = head;
        ListNode* p = &dummy;
        while(p != nullptr && p->next != NULL){
            if(p->next->val < p->val ){
                int temp = p->next->val;
                ListNode* q = &dummy;
                while(q != NULL && q->val < temp){
                    q = q->next;
                }
                ListNode* insert = q;
                int temp2 = q -> val;
                while (q != p->next) {
                    int a = q -> next->val;
                    q->next->val = temp2;
                    temp2 = a;
                    q = q->next;
                }
                insert->val = temp;
            }
            p = p->next;
        }
        
        return head;
    }
};