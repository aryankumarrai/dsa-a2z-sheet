/*
Problem: Sum of Beauty of All Substrings
Reference: https://leetcode.com/problems/sum-of-beauty-of-all-substrings/
Difficulty: Medium


Time Complexity: O((n*n)*k)
Space Complexity: O(k)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int beautySum(string s)
    {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
        {
            unordered_map<char, int> freq;
            for (int j = i; j < s.size(); j++)
            {
                freq[s[j]]++;

                int mini = INT_MAX;
                int maxi = INT_MIN;

                for (auto f : freq)
                {
                    mini = min(f.second, mini);
                    maxi = max(f.second, maxi);
                }
                res += (maxi - mini);
            }
        }
        return res;
    }
};