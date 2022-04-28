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
    Node *mergeTwoLists(Node *a, Node *b)
    {
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;

        Node *head = NULL;
        Node *tail = NULL;
        if (a->data <= b->data)
        {
            head = tail = a;
            a = a->next;
        }
        else
        {
            head = tail = b;
            b = b->next;
        }
        while (a != NULL && b != NULL)
        {
            if (a->data <= b->data)
            {
                tail->next = a;
                tail = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                tail = b;
                b = b->next;
            }
        }
        if (a == NULL)
            tail->next = b;
        else if (b == NULL)
            tail->next = a;

        print(head);
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
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Node *head2 = new Node(15);
    head2->next = new Node(25);
    head2->next->next = new Node(45);

    Solution obj;

    obj.mergeTwoLists(head, head2);
    return 0;
}