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
    Node *partition(Node *head, int x)
    {
        Node *first = new Node(0);
        Node *second = new Node(0);
        Node *fir = first;
        Node *sec = second;
        while (head != NULL)
        {
            if (head->data < x)
            {
                fir->next = head;
                fir = fir->next;
            }
            else
            {
                sec->next = head;
                sec = sec->next;
            }
            head = head->next;
        }
        fir->next = second->next;
        sec->next = NULL;
        return first->next;
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
    head->next->next->next = new Node(30);
    cout << "Input:";
    Solution obj;
    obj.print(head);
    cout << endl;
    cout << "Output:";
    cout << obj.partition(head, 15);
    return 0;
}