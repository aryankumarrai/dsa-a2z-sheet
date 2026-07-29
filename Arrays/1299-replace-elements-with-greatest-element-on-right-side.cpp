/*
Problem: Replace Elements with Greatest Element on Right Side
Reference: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side
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
    vector<int> replaceElements(vector<int> &arr)
    {
        int mx = -1;
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            mx = max(mx, exchange(arr[i], mx));
        }
        return arr;
    }
};