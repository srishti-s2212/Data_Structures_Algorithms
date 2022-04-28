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
    // Naive Method - use stack or vector
    // Efficient method is to change direction of pointers: -
    Node *reverseList(Node *head)
    {
        Node *curr = head;
        Node *prev = NULL;
        while (curr != NULL)
        {
            Node *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        head = prev;
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
    cout << "Input:";
    Solution obj;
    obj.print(head);
    cout << endl;
    cout << "Output:";
    head = obj.reverseList(head);
    obj.print(head);
    return 0;
}