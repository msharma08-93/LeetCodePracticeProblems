// Bitflip.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rem = 1;
        uint32_t rbnum = 0; //Reverse bit number 
        uint32_t temp = n; //Initializing temp to n
        uint32_t multi = pow(2,31);
        for (int i = 0; i < 32; i++)
        {
            rem = (temp % 2);
            temp = temp / 2; 
            rbnum += multi * rem;
            multi = multi / 2;
        }

        uint32_t rev = 1;
        return rbnum;
    }
};

int main()
{
    uint32_t a = 1; //01 ans-> 

    Solution s;
    std::cout << s.reverseBits(a) << "\n";

}

