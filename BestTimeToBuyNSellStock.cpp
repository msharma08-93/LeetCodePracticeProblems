// BestTimeToBuyNSellStock.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
		if (prices.size() <= 1) return 0;
		int profit = INT_MIN;
		int diff = INT_MIN;
		int prev = prices[0];
		for (int i = 1; i < prices.size(); i++)
		{
			diff = prices[i] - prev;
			if (diff > profit && diff > 0) profit = diff;
			else if (diff <= 0) prev = prices[i];
		}
		return profit>0?profit:0;
    }
};


int main()
{
	std::vector<int> v = { 3,2,3, 1, 2, 1, 3, 7, 2};
	Solution s;
	std::cout << s.maxProfit(v);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu