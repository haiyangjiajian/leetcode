//
//  148SortList.cpp
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
//    ListNode* sortList(ListNode* head) {//用快速排序出现超时
//        sortList(head,NULL);
//        return head;
//    }
//    void sortList(ListNode* head, ListNode* end){
//        if(head!=end){
//            ListNode* p = partion(head,end);
//            sortList(head, p);
//            sortList(p->next, end);
//        }
//    }
//    ListNode* partion(ListNode* head, ListNode* end){
//        int key = head->val;
//        ListNode* p = head;
//        ListNode* q = head->next;
//        while (q != end) {
//            if(q->val < key){
//                p = p->next;
//                swap(p->val, q->val);
//                q = q->next;
//            }
//            else{
//                q = q->next;
//            }
//        }
//        swap(head->val, p->val);
//        return p;
//        
//    }
    ListNode* merge(ListNode* a, ListNode* b){
        if(a == nullptr)
            return b;
        if(b == nullptr)
            return a;
        if(a->val <= b->val){
            a->next = merge(a->next, b);
            return a;
        }
        else{
            b->next = merge(a, b->next);
            return b;
        }
    }
    
    ListNode* sortList(ListNode* head){
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow;
        slow = slow -> next;
        fast ->next = nullptr;
        return merge(sortList(head), sortList(slow));
    }
    
};