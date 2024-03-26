# Additive sequence

# https://www.geeksforgeeks.org/problems/additive-sequence/1

# Given a string n, your task is to find whether it contains an additive sequence or not. A string n contains an additive sequence if its digits can make a sequence of numbers in which every number is addition of previous two numbers. You are required to complete the function which returns true if the string is a valid sequence else returns false. For better understanding check the examples.

#Note: A valid string should contain at least three digit to make one additive sequence. 

#Example 1:

#Input:  
#n = "1235813"
#Output: 
#1
#Explanation: 
#The given string can be splited into a series of numbers  
#where each number is the sum of the previous two numbers: 
#1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8, and 5 + 8 = 13. Hence, the output would be 1 (true).
#Example 2:

#Input:  
#n = "11235815"
#Output: 
#0
#Explanation: 
#We can start with the first two digits: "11".
#First number: 1, Second number: 1, Sum: 1 + 1 = 2
#Now, we have "2" as the next number.
#First number: 1, Second number: 2, Sum: 1 + 2 = 3
#Now, we have "3" as the next number.
#First number: 2, Second number: 3, Sum: 2 + 3 = 5
#Now, we have "5" as the next number.
#First number: 3, Second number: 5, Sum: 3 + 5 = 8
#Now, we have "8" as the next number.
#First number: 5, Second number: 8, Sum: 5 + 8 = 13
#At this point, there is no "13" present in the remaining digits "815". Hence, the output would be 0 (or false).
#User Task: 
#Your task is to complete the function isAdditiveSequence() which takes a single string as input n and returns a boolean value indicating whether the given string contains an additive sequence or not. You need not take any input or print anything.

#Expected Time Complexity: O(n3).
#Expected Auxiliary Space: O(1).

#Constraints:
#3 <= lenght( n ) <= 200
#1 <= digits of string <= 9


#{ 
 # Driver Code Starts
#Initial Template for Python 3

# } Driver Code Ends
#User function Template for python3

# return 1 in case of True and 0 in case of False
class Solution:
    def isAdditiveSequence(self, n):
        for i1 in range(len(n)-2):
            k=int(n[0:i1+1])
            for i2 in range(i1+1,len(n)-1):
                n2=int(n[i1+1:i2+1])
                s=n[0:i2+1]
                i=i2+1
                n1=k
                while len(s)<len(n):
                    t=n1+n2
                    n1=n2
                    n2=t
                    s+=str(t)
                if len(n)==len(s) and s==n:
                    return 1
        return 0

#{ 
 # Driver Code Starts.
        
if __name__ == "__main__":
    sol = Solution()
    t = int(input())
    for _ in range(t):
        s = input()
        print(sol.isAdditiveSequence(s))

# } Driver Code Ends