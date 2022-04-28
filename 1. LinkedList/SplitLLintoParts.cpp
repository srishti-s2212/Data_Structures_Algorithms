#include <iostream>
#include <vector>

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
    vector<Node *> splitListToParts(Node *head, int k)
    {
        vector<Node *> ans;
        Node *temp = head;
        int part = 0, listlen = 0;

        while (temp != nullptr)
        {
            temp = temp->next;
            listlen++;
        }

        temp = head;
        Node *t = temp;

        if (listlen < k)
        {

            while (temp != nullptr)
            {
                t = temp;
                temp = temp->next;
                t->next = nullptr;
                ans.push_back(t);
            }
            while (ans.size() != k)
            {
                t = nullptr;
                ans.push_back(t);
            }
        }
        else
        {
            while (temp != nullptr)
            {

                if (listlen % k > 0)
                    part = listlen / k + 1;
                else
                    part = listlen / k;

                listlen -= part;
                k--;

                t = temp;
                while (part - 1)
                {
                    temp = temp->next;
                    part--;
                }
                Node *end = temp;
                temp = temp->next;
                end->next = nullptr;
                ans.push_back(t); // Storing each part.
            }
        }
        return ans;
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
    vector<Node *> v = obj.splitListToParts(head, 2);
    obj.print(head);
    return 0;
}