/*349. Intersection of Two Arrays

https://leetcode.com/problems/intersection-of-two-arrays

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

*/

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> st;
        vector<int> ans;

        for (auto it : nums1)
        {
            st.insert(it);
        }

        for (auto it : nums2)
        {
            if (st.count(it))
            {
                ans.push_back(it);
                st.erase(it);
            }
        }
        return ans;
    }
};