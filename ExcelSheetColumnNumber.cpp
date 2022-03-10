// ExcelSheetColumnNumber.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

class Solution {
public:
    int titleToNumber(std::string columnTitle) {
        int n = columnTitle.size();
        int count = 0;
        for (int i = n-1; i >= 0; --i)
        {
            count += (int(columnTitle[i]) - int('A') + 1)*pow(26,n-i-1);
        }
        return count;
    }

    int pow(int num, int rt) {
        int res = 1;
        for (int i = 0; i < rt; i++)
        {
            res *= num;
        }
        return res;
    }
};

int main()
{
    Solution s;
    std::cout << s.titleToNumber("AB") << "\n";
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
