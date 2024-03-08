/* Check if frequencies can be equal

 https://www.geeksforgeeks.org/problems/check-frequencies4211/1

 Given a string s which contains only lower alphabetic characters, check if it is possible to remove at most one character from this string in such a way that frequency of each distinct character becomes same in the string. Return true if it is possible to do else return false.

Note: The driver code print 1 if the value returned is true, otherwise 0.

Example 1:

Input:
s = "xyyz"
Output:
1
Explanation:
Removing one 'y' will make frequency of each character to be 1.
Example 2:

Input:
s = "xxxxyyzz"
Output:
0
Explanation:
Frequency can not be made same by removing at most one character.
Your Task:
You dont need to read input or print anything. Complete the function sameFreq() which takes a string as input parameter and returns a boolean value denoting if same frequency is possible or not.

Expected Time Complexity: O(|s|)
Expected Auxiliary Space: O(1)

Constraints:
1 <= |s| <= 105


*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    bool sameFreq(string s)
    {
        unordered_map<char, int> map;
        int freq = 0;

        for (char ch : s)
            if (++map[ch] > freq)
                freq = map[ch];
        if (map.size() == 1)
            return 1;

        bool flag = true;
        for (auto it : map)
        {
            if (it.second == 1)
                continue;
            if (it.second != freq)
            {
                flag = false;
                break;
            }
        }

        if (flag)
            return 1;
        flag = true;
        for (auto it : map)
        {
            if (it.second == freq)
            {
                if (flag)
                    flag = false;
                else
                    return 0;
            }
            else if (it.second != freq - 1)
                return 0;
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.sameFreq(s) << endl;
    }
}

// } Driver Code Ends