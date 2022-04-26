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
    void print(Node *head)
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
    Node *reverse(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
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
    Node *addTwoNumbers(Node *l1, Node *l2)
    {

        Node *a = reverse(l1);
        cout << endl;
        Node *b = reverse(l2);
        Node *head = new Node(0);
        Node *curr = head;
        int carry = 0;
        int x, y;
        while (a != NULL || b != NULL)
        {
            if (a == NULL)
                x = 0;
            else
                x = a->data;

            if (b == NULL)
                y = 0;
            else
                y = b->data;

            int sum = x + y + carry;
            carry = sum / 10;
            sum = sum % 10;
            // cout<<sum;
            curr->next = new Node(sum);
            curr = curr->next;
            if (a != NULL)
                a = a->next;
            if (b != NULL)
                b = b->next;
        }
        if (carry > 0)
            curr->next = new Node(carry);
        return reverse(head->next);
    }
};
int main()
{
    Solution obj;
    Node *l1 = new Node(3);
    l1->next = new Node(4);
    l1->next->next = new Node(2);
    obj.print(l1);

    Node *l2 = new Node(4);
    l2->next = new Node(6);
    l2->next->next = new Node(5);
    obj.print(l2);

    Node *head = obj.addTwoNumbers(l1, l2);
    obj.print(head);
    return 0;
}