/*
Problem: Median of Two Sorted Arrays
Reference: https://leetcode.com/problems/median-of-two-sorted-arrays/
Difficulty: Hard


Time Complexity: O(log(min(m,n)))
Space Complexity: O(1)
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int low = 0;
        int high = m;
        while (low <= high)
        {
            int mid1 = (low + high) / 2;
            int mid2 = ((m + n + 1) / 2) - mid1;

            int l1, l2;
            if (mid1 == 0)
            {
                l1 = INT_MIN;
            }
            else
            {
                l1 = nums1[mid1 - 1];
            }

            if (mid2 == 0)
            {
                l2 = INT_MIN;
            }
            else
            {
                l2 = nums2[mid2 - 1];
            }

            int r1, r2;
            if (mid1 == m)
            {
                r1 = INT_MAX;
            }
            else
            {
                r1 = nums1[mid1];
            }

            if (mid2 == n)
            {
                r2 = INT_MAX;
            }
            else
            {
                r2 = nums2[mid2];
            }

            if (l1 <= r2 && l2 <= r1)
            {
                if ((m + n) % 2 == 0)
                {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
                else
                {
                    return max(l1, l2);
                }
            }
            else if (l1 > r2)
            {
                high = mid1 - 1;
            }
            else
            {
                low = mid1 + 1;
            }
        }
        return 0.0;
    }
};