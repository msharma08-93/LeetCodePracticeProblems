// MergeSortedArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
		int j = 0;
		for (int i = 0; i < (m+n); i++)
		{
			if (j < n)
			{
				if (nums2[j] <= nums1[i])
				{
					nums1.insert(nums1.begin() + i, nums2[j]);
					nums1.pop_back();
					j += 1;
				}
				if (nums1[i] == 0 && i >= m+j)
				{
					nums1.insert(nums1.begin() + i, nums2[j]);
					nums1.pop_back();
					j += 1;
				}
			}
		}
    }
};

int main()
{
	std::vector<int> a = { -1, 3, 0, 0, 0, 0, 0 };
	std::vector<int> b = { 0, 0, 1, 2, 3 };
	Solution s;
	s.merge(a, a.size()-b.size(), b, b.size());

	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << " ";
	}

}

