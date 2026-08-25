/*
Problem: Sort Characters By Frequency
Reference: https://leetcode.com/problems/sort-characters-by-frequency/
Difficulty: Medium


Time Complexity: O(n + k(log(k)))
Space Complexity: O(n+k)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> cnt;
        string res = "";
        for (char c : s)
            cnt[c]++;
        vector<pair<char, int>> srt(cnt.begin(), cnt.end());
        sort(srt.begin(), srt.end(), [](const pair<char, int> &a, const pair<char, int> &b)
            { return a.second > b.second; });
        for (const auto &[chr, freq] : srt)
        {
            res.append(freq, chr);
        }
        return res;
    }
};