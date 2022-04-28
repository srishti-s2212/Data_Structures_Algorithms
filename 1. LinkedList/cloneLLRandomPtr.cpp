#include <iostream>
#include <stdio.h>

using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *root)
    {
        // Step 1: Copy next by inserting nodes in between original nodes,
        // Step 2: Copy Random ptr in the inserted copy nodes
        // Step 3: Remove link(next and random ptr) b/w original and copied  nodes

        // Base Condition
        if (root == NULL)
            return NULL;

        Node *curr = root;
        // Step 1:
        while (curr != NULL)
        {
            Node *tempNext = curr->next;
            Node *clonedNode = new Node(curr->val);
            curr->next = clonedNode;
            clonedNode->next = tempNext;
            curr = tempNext;
        }

        // Step 2:
        //  Node* curr1=root;
        //  for(curr1=root; curr1->next!=NULL; curr1=curr1->next->next)
        //  {
        //      if(curr1->random->next == NULL)
        //          curr1->next->random = NULL;
        //      else
        //          curr1->next->random = curr1->random->next;
        //  }
        curr = root;
        while (curr)
        {
            if (curr->next)
                curr->next->random = curr->random ? curr->random->next : curr->random;

            // move to the next newly added node by
            // skipping an original node
            curr = curr->next ? curr->next->next : curr->next;
        }

        // Step 3:
        Node *origNode = root;
        Node *clonedNode = root->next;
        Node *clonedRoot = root->next;
        while (clonedNode != NULL || origNode != NULL)
        {
            origNode->next = (origNode->next == NULL) ? NULL : origNode->next->next;
            clonedNode->next = (clonedNode->next == NULL) ? NULL : clonedNode->next->next;
            origNode = origNode->next;
            clonedNode = clonedNode->next;
        }
        return clonedRoot;
    }
    void print(Node *start)
    {
        Node *ptr = start;
        while (ptr)
        {
            cout << "Data = " << ptr->val << ", Random  = "
                 << ptr->random->val << endl;
            ptr = ptr->next;
        }
    }
};

int main()
{
    Node *start = new Node(1);
    start->next = new Node(2);
    start->next->next = new Node(3);
    start->next->next->next = new Node(4);
    start->next->next->next->next = new Node(5);

    // 1's random points to 3
    start->random = start->next->next;

    // 2's random points to 1
    start->next->random = start;

    // 3's and 4's random points to 5
    start->next->next->random =
        start->next->next->next->next;
    start->next->next->next->random =
        start->next->next->next->next;

    // 5's random points to 2
    start->next->next->next->next->random =
        start->next;

    Solution obj;
    cout << "Original list : \n";
    obj.print(start);

    cout << "\nCloned list : \n";
    Node *cloned_list = obj.copyRandomList(start);
    obj.print(cloned_list);

    return 0;
}
