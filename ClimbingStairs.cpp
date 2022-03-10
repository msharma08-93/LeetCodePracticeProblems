// ClimbingStairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// This is dynamic programming problem solved by using recursive priciples

#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        //Number of ways to reach nth step from n-1th step uniquely
        int prev1 = 1;
        //Number of ways to reach nth step from n-2the step uniquely
        int prev2 = 1;
        //Total ways in which one can reach nth step from n-2
        int total = 0;
        int temp = 0;

        for (int i = 2; i <= n; i++)
        {
            //When we move forward total will become the ways to reach nth so prev1 and prev1 will become prev2 
            total = prev1 + prev2;
            temp = prev1;
            prev1 = total;
            prev2 = temp;
        }

        return total;
    }
};

int main()
{
    Solution s;
    std::cout << s.climbStairs(1) << "\n";
}  
