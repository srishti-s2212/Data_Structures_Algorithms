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
    bool isPalindrome(Node *head)
    {
        Node *prev = NULL, *fast = head, *slow = head, *temp;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;

            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }

        if (fast)
            slow = slow->next;

        while (slow && prev)
        {
            if (slow->data != prev->data)
                return false;
            prev = prev->next;
            slow = slow->next;
        }
        return true;
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
    cout << obj.isPalindrome(head);
    return 0;
}