/*
Problem: Longest Repeating Character Replacement
Reference: https://leetcode.com/problems/longest-repeating-character-replacement/
Difficulty: Medium


Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        vector<int> freq(26, 0);
        int left = 0, right = 0;
        int maxCount = 0;
        int maxLength = 0;
        while (right < s.size())
        {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);
            while ((right - left + 1) - maxCount > k)
            {
                freq[s[left] - 'A']--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};