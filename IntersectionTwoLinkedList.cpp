// IntersectionTwoLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(),next(NULL){}
    ListNode(int x) : val(x),next(NULL){} 
};

class SimpleSolution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* l1 = headA; 
        ListNode* l2 = headB;

        while (l2 != NULL)
        {
            while (l1 != NULL)
            {
                std::cout << "l1slow: " << l1 << ", l2: " << l2 << "\n";
                if (l2 == l1)
                {
                    return l2;
                }
                l1 = l1->next;
            }
            l2 = l2->next;
            l1 = headA;
        }

        return NULL;
    }
};

class QuickSolution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;

        while (l1 != NULL && l2 != NULL && l1 != l2)
        {
            l1 = l1->next;
            l2 = l2->next;
            if (l1 == l2) return l1;
            if (l1 == NULL) l1 = headB;
            if (l2 == NULL) l2 = headA;
        }

        return l2;
    }
};

void printlist(ListNode* head) {
    ListNode* loc = head;
    while (loc != NULL)
    {
        std::cout << loc->val << " ";
        loc = loc->next;
    }
    std::cout << "\n";
}

int main()
{
    ListNode* headA = new ListNode();
    ListNode* headB = new ListNode();
    ListNode* headC = new ListNode();
    ListNode* temp = new ListNode();

    temp = headC;
    for (int i = 5; i < 10; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    headC = headC->next;

    temp = headA;
    for (int i = -3; i < 2; i++)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    temp->next = headC;

    temp = headB;
    for (int i = -10; i < 2; i = i+2)
    {
        temp->next = new ListNode(i);
        temp = temp->next;
    }
    temp->next = headC;

    headA = headA->next;
    headB = headB->next;

    printlist(headC);
    printlist(headA);
    printlist(headB);

    std::cout << headC << "\n";

    QuickSolution s;
    std::cout << s.getIntersectionNode(headA, headB);

}
