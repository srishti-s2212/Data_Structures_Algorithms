
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
    Node *deleteDuplicates(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        Node *curr = head;
        while (curr->next != NULL)
        {
            if (curr->data == curr->next->data)
            {
                curr->next = curr->next->next;
            }
            else
                curr = curr->next;
        }
        return head;
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
    head->next->next = new Node(20);
    head->next->next->next = new Node(40);

    cout << "Input:";
    Solution obj;
    obj.print(head);
    head = obj.deleteDuplicates(head);
    cout << "Output:";
    obj.print(head);
    return 0;
}