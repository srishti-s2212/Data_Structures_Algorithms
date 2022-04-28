
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
    void rotateRight_clockwise(Node *head, int k)
    {

        if (head == nullptr || head->next == nullptr)
            return;

        Node *t = head;
        int i = 0;
        while (t)
            ++i, t = t->next;
        k = k % i;

        while (k)
        {
            t = head;
            while (t->next->next)
                t = t->next;
            t->next->next = head;
            head = t->next;
            t->next = nullptr;
            --k;
        }
        cout << "\nOutput: Clockwise rotate: ";
        print(head);
        return;
    }

    void rotateLeft_anticlock(Node *head, int k)
    {

        Node *temp = NULL;
        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;

        while (k--)
        {
            Node *temp = new Node(head->data);
            curr->next = temp;
            curr = temp;
            Node *headToDel = head;
            head = head->next;
            delete headToDel;
        }
        cout << "\nOutput: Anticlockwise rotate:";
        print(head);
        return;
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
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Input:";
    Solution obj;
    obj.print(head);
    obj.rotateLeft_anticlock(head, 2);
    obj.rotateRight_clockwise(head, 2);
    return 0;
}