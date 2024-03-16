/*525. Contiguous Array

https://leetcode.com/problems/contiguous-array/?envType=daily-question&envId=2024-03-16

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.

*/

class Solution
{
public:
    int findMaxLength(std::vector<int> &nums)
    {
        std::unordered_map<int, int> sumMap;
        int maxLength = 0;
        int sum = 0;

        sumMap[0] = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            sum += (nums[i] == 1) ? 1 : -1;
            if (sumMap.find(sum) != sumMap.end())
            {
                maxLength = std::max(maxLength, i - sumMap[sum]);
            }
            else
            {
                sumMap[sum] = i;
            }
        }
        return maxLength;
    }
};
