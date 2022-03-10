// LinkedListCycle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* slnode(int val) {
     ListNode* l = new ListNode(val);
     return l;
 }


class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};


int main()
{
    ListNode* head = slnode(1);
    head->next = slnode(2);
    head->next->next = slnode(3);
    head->next->next->next = slnode(4);
    head->next->next->next->next = head->next;

    Solution s;
    std::cout << s.hasCycle(head);

}
