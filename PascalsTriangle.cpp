// PascalsTriangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> pt;
        std::vector<int> curv = {1};
        std::vector<int> prev = {1};

        for (int j = 1; j <= numRows; j++)
        {
            curv = ptrow(prev, j);
            pt.push_back(curv);
            prev = curv;
        }

        return pt;
    }

    std::vector<int> ptrow(std::vector<int>& prev, int sz) {
        if (sz == 1) return { 1 };
        std::vector<int> tempv(sz,1);
        int len = (sz % 2 != 0) ? sz / 2 + 1 : sz / 2;

        for (int i = 1; i < len; i++)
        {
            tempv[i] = prev[i-1] + prev[i];
            tempv[sz-1 - i] = tempv[i];
        }

        return tempv;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> vect = s.generate(5);
    
    for (auto& vec : vect)
    {
        for (int j = 0; j < vec.size(); j++)
        {
            std::cout << vec[j] << " ";
        }
        std::cout << "\n";
    }

}
