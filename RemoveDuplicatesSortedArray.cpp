// RemoveDuplicatesSortedArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 1, j = 0;


        while (i < nums.size()) 
        {
            if (nums[j] != nums[i])
            {
                j += 1;
                nums[j] = nums[i];
            }
            i += 1;
        }

        return j+1;
    }
};

class Sol1 {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;
        for (int j = 1; j < nums.size(); j++)
        {
            if (nums[j] > nums[i]) nums[i++] = nums[j];
        }
        return i;
    }
};

int main()
{
    std::vector<int> v1 = { 1,1,2 };
    Sol1 s1;
    int b = s1.removeDuplicates(v1);
    std::cout << "Number of Duplicates : " << b << "\n";

    for (int i = 0; i < b; i++)
    {
        std::cout << v1[i] << " ";
    }
}

