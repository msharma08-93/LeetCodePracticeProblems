// LongestCommonPrefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.size() == 0)
        {
            return "";
        }

        return commonPrefix(strs, 0, strs.size()-1);

    }

    std::string commonPrefix(std::vector<std::string>& strnew, int l, int r) {
        if (l == r)
        {
            return strnew[l];
        }

        int mid = (l + r) / 2;
        std::string left = commonPrefix(strnew, l, mid);
        std::string right = commonPrefix(strnew, mid + 1, r);
        return prefixTwo(left, right);
    }

    std::string prefixTwo(std::string left, std::string right) {
        int len = left.size() < right.size() ? left.size() : right.size();
        for (int i = 0; i < len; i++)
        {
            if (left[i] != right[i])
            {   
                return left.substr(0, i);
            }
        }
        return left.substr(0, len);
    }
};

int main()
{
    Solution s1;
    std::vector<std::string> input = { "flower", "flow", "flowing" };
    std::cout << s1.longestCommonPrefix(input);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
