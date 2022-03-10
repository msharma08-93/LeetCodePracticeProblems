// HammingWeight.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t div = n;
        uint32_t rem = 0; // divided and remainder 
        int count = 0;

        while (div > 0) {
            rem = div % 2;
            div = div / 2;
            if (rem != 0) count += 1;
        }

        return count;
   
    }
};

class BrianKer {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            n = n & (n - 1);
            count += 1;
        }
        return count;
    }
};

int main()
{
    uint32_t a = 54;
    Solution s;
    BrianKer b;
    std::cout << b.hammingWeight(a);

}