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
    // Naive: -
    // Node* removeNthFromEnd(Node* head, int n) {
    //          Node* curr=head;
    //          int len=0;
    //          for(curr=head;curr!=NULL;curr=curr->next)
    //              len++;
    //          if(n>len)
    //              return NULL;
    //          curr=head;
    //          for(int i=1;i<=len-n-1;i++)
    //              curr=curr->next;

    //         Node* temp=curr->next;
    //         curr->next=curr->next->next;
    //         delete(temp);
    //         return head;
    //     }

    Node *removeNthFromEnd(Node *head, int n)
    {
        int size = n;
        Node *first = head;
        for (int i = 1; i <= n; i++)
            first = first->next;
        Node *second = head;
        Node *prev;
        while (first != NULL)
        {
            prev = second;
            second = second->next;
            first = first->next;
            size++;
        }
        // Checking edge case... if the 1st element is needed to be deleted
        if (size == n)
            return head->next;
        // cout<<"Data to delete"<<second->val;
        prev->next = second->next;
        delete second;
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
    int n = 2;
    cout << endl;
    cout << "Output Naive:";
    head = obj.removeNthFromEnd(head, n);
    obj.print(head);
    return 0;
}