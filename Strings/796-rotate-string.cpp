/*
Problem: Rotate String
Reference: https://leetcode.com/problems/rotate-string/
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
    bool rotateString(string s, string goal)
    {
        if (s.size() != goal.size())
            return 0;
        string n = s + s;
        return (n.find(goal) != string::npos);
    }
};