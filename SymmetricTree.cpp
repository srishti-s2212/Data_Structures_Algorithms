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
    bool isSymmetric(Node *root)
    {
        if (root == NULL)
            return true;
        return (isSymmetricUtil(root->left, root->right));
    }

    bool isSymmetricUtil(Node *n1, Node *n2)
    {
        if (n1 == NULL && n2 == NULL)
            return true;
        if (n1 == NULL || n2 == NULL)
            return false;
        if ((n1->val == n2->val) && isSymmetricUtil(n1->left, n2->right) && isSymmetricUtil(n1->right, n2->left))
            return true;
        return false;
    }
};