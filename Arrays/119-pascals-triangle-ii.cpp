/*
Problem: Pascal's Triangle II
Reference: https://leetcode.com/problems/pascals-triangle-ii
Difficulty: Easy


Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    vector<int> getRow(int n)
    {
        long long ans = 1;
        vector<int> res = {1};
        for (int i = 1; i <= n; i++)
        {
            ans *= (n - i) + 1;
            ans /= i;
            res.push_back(ans);
        }
        return res;
    }
};