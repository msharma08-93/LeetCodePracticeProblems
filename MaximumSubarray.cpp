// MaximumSubarray.cpp : This file contains the 'main' function. Program execution begins and ends there

#include <iostream>
#include <vector>
#include <algorithm>

//Solution that returns the subarray as well
//class Solution {
//public:
//    int maxSubArray(std::vector<int>& nums) {
//        int vecsum = nums[0];
//        int idx1 = 0;
//        int idx2 = 0;
//
//        for (int i = 0; i < nums.size(); i++)
//        {
//            int sum = nums[i];
//            for (int j = i; j < nums.size(); j++)
//            {
//                if (i != j)
//                {
//                    sum += nums[j];
//                }
//                if (sum > vecsum)
//                {
//                    vecsum = sum;
//                    idx1 = i;
//                    idx2 = j;
//                }
//            }
//        }
//
//        std::vector<int> resvec;
//        for (int m = idx1; m <= idx2; m++)
//        {
//            resvec.push_back(nums[m]);
//        }
//
//        nums = resvec;
//
//        return vecsum;
//    }
//};

//Kadane's Algorithm 
class Solution {
public: 
    int maxSubArray(std::vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currSum += nums[i];
            if (maxSum < currSum)
            {
                maxSum = currSum;
            }
            if (currSum < 0)
            {
                currSum = 0;
            }
        }
        return maxSum;
    }
};

int main()
{
    std::vector<int> v1 = { -2,1};
    Solution s1;

    std::cout << "Max sum = " << s1.maxSubArray(v1) << "\n";

}
