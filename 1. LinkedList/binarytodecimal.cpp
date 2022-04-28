#include <iostream>
#include <math.h>
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
    int getDecimalValue(Node *head)
    {
        Node *p = head;
        int dec = 0, count = 0;
        long long base;
        while (p != NULL)
        {
            p = p->next;
            count++;
        }
        base = count - 1;
        p = head;
        while (p != NULL)
        {
            dec = dec + (p->data * pow(2, base));
            base -= 1;
            p = p->next;
        }
        return dec;
    }
};
int main()
{
    Node *head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);
    Solution obj;
    cout << obj.getDecimalValue(head);
    return 0;
}