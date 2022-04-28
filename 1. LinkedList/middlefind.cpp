#include <iostream>
#include <stdio.h>

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
    Node *middle(Node *head)
    {
        if (head == NULL)
            return head;

        Node *slow, *fast;
        slow = fast = head;
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // mid=slow
        return slow;
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
    Solution obj;
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    cout << "Input:";
    obj.print(head);
    cout << endl;
    head = obj.middle(head);
    cout << "Output:";
    obj.print(head);
    return 0;
}
