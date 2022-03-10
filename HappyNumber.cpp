// HappyNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while (slow != 1 && fast != 1)
        {
            slow = sumsqdig(slow);
            fast = sumsqdig(sumsqdig(fast));
            if (slow == fast && slow != 1) return false;
        }

        return true;
    }

    int sumsqdig(int n) {
        int rem = 0;
        int sqsumdig = 0;
        while (n > 0)
        {
            rem = n % 10;
            sqsumdig += rem * rem;
            n = n / 10;
        }

        return sqsumdig;
    }
};

int main()
{
    Solution s;
    std::cout << s.isHappy(18);

}
