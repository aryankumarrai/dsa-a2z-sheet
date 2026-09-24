/*
Problem: Lemonade Change
Reference: https://leetcode.com/problems/lemonade-change/
Difficulty: Easy


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int five = 0;
        int ten = 0;
        for (int i : bills)
        {
            if (i == 5)
            {
                five++;
            }
            else if (i == 10)
            {
                if (five > 0)
                {
                    five--;
                    ten++;
                }
                else
                    return 0;
            }
            else if (i == 20)
            {
                if (ten > 0 && five > 0)
                {
                    ten--;
                    five--;
                }
                else if (five >= 3)
                {
                    five -= 3;
                }
                else
                    return 0;
            }
        }
        return 1;
    }
};