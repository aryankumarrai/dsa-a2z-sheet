/*
Problem: Longest Consecutive Sequence
Reference: https://leetcode.com/problems/longest-consecutive-sequence
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
    int longestConsecutive(vector<int> &nums)
    {
        int maxconseq = 0;
        unordered_set<int> temp;
        for (int i : nums)
        {
            temp.insert(i);
        }
        for (int i : temp)
        {
            if (temp.find(i - 1) == temp.end())
            {
                int curr = i;
                int currconseq = 1;
                while (temp.find(curr + 1) != temp.end())
                {
                    curr++;
                    currconseq++;
                }
                maxconseq = max(maxconseq, currconseq);
            }
        }
        return maxconseq;
    }
};