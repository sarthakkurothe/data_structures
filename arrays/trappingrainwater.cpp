/*42. Trapping Rain Water

https://leetcode.com/problems/trapping-rain-water/description/

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.



Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
Example 2:

Input: height = [4,2,0,3,2,5]
Output: 9


 */

class Solution
{
public:
    int trap(vector<int> &height)
    {

        int n = height.size();
        int L = 0;
        int R = n - 1;
        int ans = 0;
        int mx = 0;
        while (L < R)
        {

            int water = mx - min(height[L], height[R]);
            if (water > 0)
            {
                ans += water;
            }

            if (height[L] < height[R])
            {
                mx = max(mx, height[L++]);
            }
            else
            {
                mx = max(mx, height[R--]);
            }
        }

        return ans;
    }
};