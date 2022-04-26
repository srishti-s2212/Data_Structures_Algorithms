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
    void deleteNode(Node *nodeDel)
    {
        nodeDel->data = nodeDel->next->data;
        Node *temp = nodeDel->next;
        nodeDel->next = nodeDel->next->next;
        delete temp;
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
    cout << "Output Naive:";
    obj.deleteNode(head->next);
    obj.print(head);
    return 0;
}