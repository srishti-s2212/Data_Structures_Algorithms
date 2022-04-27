#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
        this->next = NULL;
    }
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *prev = NULL;
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
                if (prev != NULL)
                    prev->next = curr;
                prev = curr;
            }
            prev->next = NULL;
        }
        return root;
    }
};

int main()
{
    /* Constructed binary tree is
            10
            / \
        8 2
        /     \
    3     90
    */
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->right->right = new Node(90);

    // Populates nextRight pointer in all nodes
    Solution obj;
    // cout << "Test";
    obj.connect(root);
    // cout << "Test2";

    // Let us check the values of nextRight pointers
    cout << "Following are populated nextRight pointers in the tree"
            " (-1 is printed if there is no nextRight) \n";
    cout << "nextRight of " << root->val << " is "
         << (root->next ? root->next->val : -1) << endl;
    cout << "nextRight of " << root->left->val << " is "
         << (root->left->next ? root->left->next->val : -1) << endl;
    cout << "nextRight of " << root->right->val << " is "
         << (root->right->next ? root->right->next->val : -1) << endl;
    cout << "nextRight of " << root->left->left->val << " is "
         << (root->left->left->next ? root->left->left->next->val : -1) << endl;
    cout << "nextRight of " << root->right->right->val << " is "
         << (root->right->right->next ? root->right->right->next->val : -1) << endl;
    return 0;
}