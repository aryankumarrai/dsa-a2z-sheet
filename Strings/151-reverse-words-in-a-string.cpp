/*
Problem: Reverse Words in a String
Reference: https://leetcode.com/problems/reverse-words-in-a-string/
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    string reverseWords(string s)
    {
        int n = s.size() - 1;
        string res = "";
        while (n >= 0)
        {
            while (n >= 0 && s[n] == ' ')
            {
                n--;
            }
            if (n < 0)
            {
                break;
            }
            int end = n;
            while (n >= 0 && s[n] != ' ')
            {
                n--;
            }
            string temp = s.substr(n + 1, end - n);
            if (!res.empty())
            {
                res += " ";
            }
            res += temp;
        }
        return res;
    }
};