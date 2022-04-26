
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
    Node *deleteAllOccurrences(Node *head, int x)
    {
        while (head != NULL && head->data == x)
        {
            head = head->next;
        }
        Node *curr = head;
        while (curr != NULL && curr->next != NULL)
        {
            if (curr->next->data == x)
            {
                curr->next = curr->next->next;
            }
            else
            {
                curr = curr->next;
            }
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
    head->next->next = new Node(30);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(50);
    cout << "Input:";
    Solution obj;
    obj.print(head);
    cout << endl;
    cout << "Output:";
    head = obj.deleteAllOccurrences(head, 30);
    obj.print(head);
    return 0;
}