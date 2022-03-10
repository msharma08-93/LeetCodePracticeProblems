// MajorityElement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::map<int, int> m;
        
        for (int i = 0; i < nums.size(); i++)
        {

            if (m.end() == m.find(nums[i]))
            {
                m.insert({ nums[i],1 });
            }
            else 
            {
                m[m.find(nums[i])->first] = m.find(nums[i])->second + 1;
            }
            if (m.find(nums[i])->second > nums.size() / 2) return m.find(nums[i])->first;
        }
    }
};

int main()
{
    std::vector<int> v = {1,1,1, 2, 2, 1, 1, 1, 2, 2 };
    Solution s;
    std::cout << "Majority Element: " << s.majorityElement(v);
}

