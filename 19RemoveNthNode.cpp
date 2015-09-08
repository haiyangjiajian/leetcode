//
//  19RemoveNthNode.cpp
//  TestC
//
//  Created by ZhaoHaiyang on 15/8/23.
//  Copyright (c) 2015年 ZhaoHaiyang. All rights reserved.
//

#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * second = head;
        if(head == NULL || n < 1){
            return head;
        }
        ListNode * first = head;
        ListNode * beforeSecond = head;
        for(int i = 1; i < n; i++){
            if(first->next == nullptr)
                return head;
            first = first->next;
        }
        if(first -> next == nullptr){//delete head
            head = head -> next;
            return head;
        }
        while(first->next != nullptr){
            first = first -> next;
            beforeSecond = second;
            second = second -> next;
            
        }
        beforeSecond ->next = second ->next;
        delete second;
        return head;
    }
};