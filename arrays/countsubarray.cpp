/*2962. Count Subarrays Where Max Element Appears at Least K Times

https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2024-03-29

You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.



Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.


Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105

*/

class Solution
{
public:
    long long int countSubs(vector<int> &nums, int k, int mx)
    {
        long long int count = 0;
        int left = 0;
        unordered_map<int, int> freq;
        for (int right = 0; right < nums.size(); ++right)
        {
            freq[nums[right]]++;
            while (freq[mx] >= k)
            {
                freq[nums[left]]--;
                left++;
            }
            count += right - left + 1;
        }
        return count;
    }
    long long countSubarrays(vector<int> &nums, int k)
    {
        int mx = -1;
        for (int m : nums)
        {
            mx = max(mx, m);
        }
        long long int Tsubs = nums.size() * (nums.size() + 1) / 2;
        return (long long)Tsubs - countSubs(nums, k, mx);
    }
};