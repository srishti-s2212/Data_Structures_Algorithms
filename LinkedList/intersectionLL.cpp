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
    Node *getIntersectionNode(Node *headA, Node *headB)
    {
        int c1 = countNode(headA);
        int c2 = countNode(headB);
        if (c1 > c2)
        {
            int d = c1 - c2;
            return (_getIntersection(d, headA, headB));
        }
        else
        {
            int d = c2 - c1;
            return (_getIntersection(d, headB, headA));
        }
    }

    Node *_getIntersection(int d, Node *headA, Node *headB)
    {
        Node *currA = headA;
        Node *currB = headB;
        for (int i = 1; i <= d; i++)
        {
            currA = currA->next;
        }

        while (currA != NULL && currB != NULL)
        {
            if (currA == currB)
                return currA;
            currA = currA->next;
            currB = currB->next;
        }
        return NULL;
    }
    int countNode(Node *head)
    {
        Node *curr = head;
        int count = 1;
        while (curr != NULL)
        {
            curr = curr->next;
            count++;
        }
        return count;
        cout << count << " ";
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
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    head1->next->next->next = new Node(40);

    Node *head2 = new Node(100);
    head2->next = new Node(30);
    head2->next->next = new Node(70);
    head2->next->next->next = new Node(80);

    head1->next->next = head2->next;
    // cout << "Input:";
    Solution obj;
    cout << (obj.getIntersectionNode(head1, head2))->data;
    return 0;
}