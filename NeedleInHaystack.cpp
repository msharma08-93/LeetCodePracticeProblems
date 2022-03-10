// NeedleInHaystack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int ns = needle.size();
        int hs = haystack.size();
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        if (hs < ns) return -1;

        for (int i = 0; i < haystack.size(); i++)
        {
            if (needle[0] == haystack[i] && (i + ns - 1) <= hs && needle[ns-1] == haystack[i+ns-1])
            {
                int j = 0;
                while (j < needle.size())
                {
                    if (needle[j] == haystack[i + j]) j += 1;
                    else break;
                }
                if (j == needle.size()) return i;
            }
        }
        return - 1;
    }
};

int main()
{
    std::string hay = "mine is yo you";
    std::string ned = "you";

    Solution s1;
    std::cout << s1.strStr(hay, ned);
}
