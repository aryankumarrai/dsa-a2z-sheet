/*
Problem: Minimum Window Substring
Reference: https://leetcode.com/problems/minimum-window-substring/
Difficulty: Hard


Time Complexity: O(n+m)
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    // Finds the minimum valid substring using a sliding window.
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        // A valid window cannot exist in these cases.
        if (n == 0 || m == 0 || n < m)
        {
            return "";
        }

        vector<int> need(128, 0);
        vector<int> window(128, 0);

        // Store how many copies of each character are required.
        for (char ch : t)
        {
            need[(unsigned char)ch]++;
        }

        int left = 0;
        int matched = 0;
        int minLength = INT_MAX;
        int startIndex = -1;

        // Expand the right boundary across the complete string.
        for (int right = 0; right < n; right++)
        {
            unsigned char current = s[right];
            window[current]++;

            // Count the new character only if a required copy is satisfied.
            if (
                need[current] > 0 &&
                window[current] <= need[current])
            {
                matched++;
            }

            // Shrink while every required character is still satisfied.
            while (matched == m)
            {
                int currentLength =
                    right - left + 1;

                // Keep the smallest valid window found so far.
                if (currentLength < minLength)
                {
                    minLength = currentLength;
                    startIndex = left;
                }

                unsigned char leftChar = s[left];
                window[leftChar]--;

                // Losing a required copy makes the window invalid.
                if (
                    need[leftChar] > 0 &&
                    window[leftChar] < need[leftChar])
                {
                    matched--;
                }

                left++;
            }
        }

        // No window contained every required character.
        if (startIndex == -1)
        {
            return "";
        }

        return s.substr(startIndex, minLength);
    }
};