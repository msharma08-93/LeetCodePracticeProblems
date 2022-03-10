// addTwoNumbers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <iterator>

//function for printing the elements in a list
void showlist(std::list <int> g)
{
   std:: list <int> ::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        std::cout << '\t' << *it;
    std::cout << '\n';
}

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* head = new ListNode(0);
        ListNode* curr = head;

        while (l1 != NULL || l2 != NULL)
        {
            if (l1 != NULL) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL)
            {
                carry += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(carry % 10);
            carry = carry / 10;
            curr = curr->next;
        }
        if (carry != 0)
        {
            curr->next = new ListNode(carry);
        }
        return head->next;
    }
};

 int main()
 {
     //std::list<int> l1;
     //l1.push_back(2);
     //l1.push_back(4);
     //l1.push_back(3);
     //showlist(l1);

     //std::list<int> l2;
     //l2.push_back(5);
     //l2.push_back(4);
     //l2.push_back(6);
     //showlist(l2);

     ListNode *head = new ListNode(2);
     head->next = new ListNode(4);
     head->next->next = new ListNode(3);

     ListNode* hit = new ListNode(5);
     hit->next = new ListNode(6);
     hit->next->next = new ListNode(4);

     //while (head != NULL) {
     //    std::cout << "Ptr : " << head->next << "    Data : " << head->val << "\n";
     //    head = head->next;
     //}

     //while (hit != NULL) {
     //    std::cout << "Ptr : " << hit->next << "    Data : " << hit->val << "\n";
     //    hit = hit->next;
     //}

     Solution add;
     ListNode* sumad = add.addTwoNumbers(hit, head);

     while (sumad != NULL)
     {
         std::cout << "Ptr : " << sumad << ", Data : " << sumad->val << ", Next Ptr : " << sumad->next << "\n";
         sumad = sumad->next;
     }



	 //while (sum->next != NULL) {
		// std::cout << "Ptr : " << sum->next << "    Data : " << sum->val << "\n";
		// sum = sum->next;
	 //}
 }