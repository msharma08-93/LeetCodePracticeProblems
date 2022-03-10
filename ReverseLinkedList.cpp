// ReverseLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            std::cout << prev->next << " " << prev->val << " " << "\n";
        }

        return prev;
    }
};

int main()
{
    ListNode* l = new ListNode;
    ListNode* ls = l;

    for (int i = 0; i < 10; i++)
    {
        ls->next = new ListNode(i);
        ls = ls->next;
    }

    //ls = l->next;
    //while (ls != NULL)
    //{
    //    std::cout << ls->val << " " << ls->next << "\n";
    //    ls = ls->next;
    //}


    Solution s;
    std::cout << s.reverseList(l->next);
     
}

