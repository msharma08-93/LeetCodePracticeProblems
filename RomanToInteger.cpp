// RomanToInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>

class Solution
{
public:
	int romanToInt(std::string s) {
		if (s.size() == 0)
		{
			return 0;
		}

		int num = 0;
		int i = 0;

		while (i < s.size())
		{
			char cur = s[i];
			int nex = (i + 1) < s.size() ? val(s[i + 1]) : 0;
			num += oper(val(cur), nex, i);
			i += 1;
		}

		return num;
	};

	int oper(int crt, int nxt, int& iter) {
		if (crt >= nxt)
		{
			return crt;
		}
		else
		{
			iter += 1;
			return (nxt - crt);
		}

	};

	int val(char b) {
		int val = 0;
		switch (b)
		{
		case 'I':
			val = 1;
			break;
		case 'V':
			val = 5;
			break;
		case 'X':
			val = 10;
			break;
		case 'L':
			val = 50;
			break;
		case 'C':
			val = 100;
			break;
		case 'D':
			val = 500;
			break;
		case 'M':
			val = 1000;
			break;
		}

		return val;
	};

};

int main()
{
	std::string s = "XIV";
	Solution s1;
	std::cout << s1.romanToInt(s) << "\n";
}

	//Experimental 
	//std::map<char, int> a;
	//a = { {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000} };

	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started: 
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
