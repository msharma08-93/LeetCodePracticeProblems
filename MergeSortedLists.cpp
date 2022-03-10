#include <iostream>

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode* next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {
            return list1;
        }
        if (list1 == NULL && list2 != NULL) {
            return list2;
        }
        if (list2 == NULL && list1 != NULL) {
            return list1;
        }

        ListNode* head = new ListNode();
        ListNode* temp = new ListNode();

        if (list1->val > list2->val) {
            head = list2;
            temp = list2;
            list2 = list2->next;
        } else {
            head = list1;
            temp = list1;
            list1 = list1->next;
        }

        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                temp->next = list1;
                temp = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                temp = list2;
                list2 = list2->next;
            }
        }

        if (list1 == NULL)
        {
            temp->next = list2;
        }
        if (list2 == NULL)
        {
            temp->next = list1;
        }

        return head;
    }
};

class recursiveSol {
public:
    ListNode* mergedSorted(ListNode* list1, ListNode* list2) {
        if (list1 == NULL && list2 == NULL) {
            return list1;
        }
        if (list1 == NULL && list2 != NULL) {
            return list2;
        }
        if (list2 == NULL && list1 != NULL) {
            return list1;
        }

        if (list1->val > list2->val)
        {
            list2->next = mergedSorted(list1, list2->next);
            return list2;
        }
        else
        {
            list1->next = mergedSorted(list1->next, list2);
            return list1;
        }

    }
};

int main()
{
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);

    ListNode* start = new ListNode(1);
    start->next = new ListNode(3);
    start->next->next = new ListNode(4);
    
    recursiveSol s1;
    ListNode* merged = new ListNode();
    merged = s1.mergedSorted(start, head);

    while (merged != NULL) {
        std::cout << merged->val << "  ";
        merged = merged->next;
    }
}
