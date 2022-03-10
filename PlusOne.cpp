
#include <iostream>
#include <vector>
#include <algorithm>

//class Solution {
//public:
//    std::vector<int> plusOne(std::vector<int>& digits) {
//        std::vector<int> vec;
//        int sum = 0, carry = 1;
//        int sz = digits.size();
//        if (sz == 0) {
//            vec.push_back(1); 
//            return vec;
//        }
//
//        sum = digits[sz - 1] + carry;
//        if (sum >= 10)
//        {
//            for (int i = sz - 1; i >= 0; i--)
//            {
//                sum = digits[i] + carry;
//                vec.push_back(sum % 10);
//                carry = sum / 10;
//            }
//            if (carry != 0)
//            {
//                vec.push_back(carry);
//            }
//        }
//        else
//        {
//            digits.pop_back();
//            digits.push_back(sum);
//            return digits;
//        }
//        std::reverse(vec.begin(), vec.end());
//        return vec;
//    }
//};

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        std::vector<int> vec;
        int sum = 0, carry = 1;
        int sz = digits.size();

        for (int i = sz - 1; i >= 0; i--)
        {
            sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if (carry == 0)
            {
                break;
            }
        }

        if (carry != 0)
        {
            digits.insert(digits.begin(),carry);
        }
        return digits;

    }
};


int main()
{
    std::vector<int> v1 = {  };

    Solution s1;
    std::vector<int> v2 = s1.plusOne(v1);
    for (int i = 0; i < v2.size(); i++)
    {
        std::cout << v2[i] << " ";
    }
}