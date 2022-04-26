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
class DeleteMiddle
{
public:
    Node *DeleteMid(Node *head)
    {
        if (head == NULL)
            return head;
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }
        Node *slow, *fast;
        slow = fast = head;
        Node *prev;
        while (fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // mid=slow
        prev->next = slow->next;
        delete slow;
        return head;
    }

    int countNoOfNode(Node *head)
    {
        if (head == NULL)
            return 0;
        Node *curr = head;
        int count = 1;
        while (curr != NULL)
        {
            curr = curr->next;
            count++;
        }
        return count;
    }
    Node *DeleteMidNaive(Node *head)
    {
        if (head == NULL)
            return NULL;
        if (head->next == NULL)
        {
            delete head;
            return NULL;
        }
        int count = countNoOfNode(head);
        cout << "Count of nodes:" << count << endl;
        int mid = count / 2;
        Node *curr = head;
        for (int i = 1; i <= mid - 2; i++)
        {
            curr = curr->next;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
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
    DeleteMiddle obj;
    obj.print(head);
    cout << endl;
    // head = obj.DeleteMid(head);
    //  cout << "Output:";
    //  obj.print(head);
    cout << "Output Naive:";
    head = obj.DeleteMidNaive(head);
    obj.print(head);
    return 0;
}