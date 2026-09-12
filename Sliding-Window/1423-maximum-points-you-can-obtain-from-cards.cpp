/*
Problem: Maximum Points You Can Obtain from Cards
Reference: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
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
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int total = 0;
        for (int i = 0; i < k; ++i)
        {
            total += cardPoints[i];
        }
        int maxPoints = total;
        for (int i = 0; i < k; ++i)
        {
            total -= cardPoints[k - 1 - i];
            total += cardPoints[n - 1 - i];
            maxPoints = max(maxPoints, total);
        }
        return maxPoints;
    }
};