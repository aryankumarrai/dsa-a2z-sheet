/*
Problem: Kth Missing Positive Number
Reference: https://leetcode.com/problems/kth-missing-positive-number/
Difficulty: Easy


Time Complexity: O(log(n))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high)
        {
            int mid = low + ((high - low) / 2);
            int temp = (arr[mid] - 1) - mid;
            if (temp >= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low + k;
    }
};