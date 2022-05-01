
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *reverseKGroup(Node *head, int k)
    {
        // Step 1: Base Condition
        if (head == NULL)
            return head;

        // To check if number of nodes <k only or not
        Node *curr = head;
        for (int i = 1; i <= k; i++)
        {
            if (curr == NULL)
                return head;
            curr = curr->next;
        }

        // Step 2: Reverse first k nodes
        curr = head;
        Node *prev = NULL;
        Node *tempNext = NULL;
        int count = 1;
        while (count <= k && curr != NULL)
        {
            tempNext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempNext;
            count++;
        }

        // Step 3: Recursion sambhal lega
        if (tempNext != NULL)
            head->next = reverseKGroup(tempNext, k);
        return prev;
    }
    void print(Node *head)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    cout << "Input:";
    Solution obj;
    obj.print(head);
    cout << endl;
    cout << "Output:";
    head = obj.reverseKGroup(head, 2);
    obj.print(head);
    return 0;
}