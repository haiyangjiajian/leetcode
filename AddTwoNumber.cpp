//
//  AddTwoNumber.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/7/24.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <stdio.h>
#include<iostream>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 ==NULL)
            return NULL;
        int temp = 0;
        ListNode* head;
        ListNode *q;
        int time = 0;
        while(l1!=NULL||l2!=NULL){
            ListNode *p ;
            if(l1!=NULL && l2 !=NULL){
                p = new ListNode( (temp + l1->val + l2->val)%10);
                temp = (temp + l1->val + l2->val)/10;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 == NULL){
                p = new ListNode( (temp + l2->val)%10);
                temp = (temp + l2->val)/10;
                l2 = l2->next;
            }
            else if(l2 == NULL){
                p = new ListNode( (temp + l1->val)%10);
                temp = (temp + l1->val)/10;
                l1 = l1->next;

            }
            if(time == 0){
                head = q = p;
            }
            else{
                q->next = p;
                q = p;
            }
            time++;
        }
        if(temp!=0){
            ListNode *p = new ListNode(temp);
            q->next= p;
        }
        return head;
    }
    
};

//int main(int argc, const char * argv[]) {
//    Solution solution;
//    ListNode * l1 = new ListNode(3);
//    ListNode *l11 = new ListNode(2);
//    l1->next = l11;
//    ListNode *l2 = new ListNode(4);
//    ListNode * head = solution.addTwoNumbers(l1, l2);
//    while(head!=NULL){
//        cout<<"ss:"<<head->val;
//        head = head->next;
//    }
//    
//}
