/*Linked List that is Sorted Alternatingly

 https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1

 You are given a Linked list of size n. The list is in alternating ascending and descending orders. Sort the given linked list in non-decreasing order.

Example 1:

Input:
n = 6
LinkedList = 1->9->2->8->3->7
Output: 1 2 3 7 8 9
Explanation:
After sorting the given list will be 1->2->3->7->8->9.
Example 2:

Input:
n = 5
LinkedList = 13->99->21->80->50
Output: 13 21 50 80 99
Explanation:
After sorting the given list will be 13->21->50->80->99.
Your Task:
You do not need to read input or print anything. The task is to complete the function sort() which should sort the linked list of size n in non-decreasing order.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= Number of nodes <= 100
0 <= Values of the elements in linked list <= 103
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
/* Function to print linked list */

void append(struct Node **headRef, struct Node **tailRef, int newData)
{
    struct Node *new_node = new Node(newData);
    struct Node *last = *headRef;
    if (*headRef == NULL)
    {
        *headRef = new_node;
        *tailRef = *headRef;
        return;
    }

    (*tailRef)->next = new_node;
    *tailRef = (*tailRef)->next;
}

// A utility function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// } Driver Code Ends

/*
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data =x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    void sort(Node **head)
    {
        Node *a = *head, *b = a->next, *h = b;
        while (a and a->next and b and b->next)
        {
            a->next = (b->next) ? b->next : nullptr, a = a->next;
            b->next = (a->next) ? a->next : nullptr, b = b->next;
        }
        Node *tmp = nullptr, *prev = nullptr, *curr = h;
        while (curr)
            tmp = curr->next, curr->next = prev, prev = curr, curr = tmp;
        a->next = prev;
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        struct Node *head = NULL;
        struct Node *tail = NULL;
        int n, k;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> k;
            append(&head, &tail, k);
        }
        Solution ob;
        ob.sort(&head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends