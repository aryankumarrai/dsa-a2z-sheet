/*
Problem: 3 Sum
Reference: https://leetcode.com/problems/3sum
Difficulty: Medium


Time Complexity: O(n*n)
Space Complexity: O(1)
*/


#include <bits/stdc++.h>

using namespace std;
using ll = long long;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> answer;

        // Three different indices are required.
        if (n < 3)
        {
            return answer;
        }

        sort(nums.begin(), nums.end());

        for (int fixed = 0; fixed < n - 2; fixed++)
        {
            /*
             * Skip the same fixed value to avoid
             * generating duplicate triplets.
             */
            if (fixed > 0 && nums[fixed] == nums[fixed - 1])
            {
                continue;
            }

            int left = fixed + 1;
            int right = n - 1;

            while (left < right)
            {
                long long sum =
                    (long long)nums[fixed] +
                    nums[left] +
                    nums[right];

                // A smaller sum needs a larger left value.
                if (sum < 0)
                {
                    left++;
                }
                // A larger sum needs a smaller right value.
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    answer.push_back({nums[fixed],
                                      nums[left],
                                      nums[right]});

                    left++;
                    right--;

                    /*
                     * Skip repeated values so the same
                     * triplet is not added again.
                     */
                    while (left < right &&
                           nums[left] == nums[left - 1])
                    {
                        left++;
                    }

                    while (left < right &&
                           nums[right] == nums[right + 1])
                    {
                        right--;
                    }
                }
            }
        }

        return answer;
    }
};