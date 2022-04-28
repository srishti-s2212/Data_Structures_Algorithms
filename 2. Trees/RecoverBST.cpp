#include <iostream>
#include <limits.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);

        if (prev != NULL && (root->val < prev->val))
        {

            // If this is first violation, mark these two nodes as
            // 'first' and 'middle'
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }

            // If this is second violation, mark this node as last
            else
                last = root;
        }

        // Mark this node as previous
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }

    void printInorder(struct TreeNode *node)
    {
        if (node == NULL)
            return;
        printInorder(node->left);
        cout << "  " << node->val;
        printInorder(node->right);
    }
};
int main()
{
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */

    struct TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(10);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(12);
    root->right->left = new TreeNode(7);

    cout << "Inorder Traversal of the original tree \n";
    Solution obj;
    obj.printInorder(root);
    obj.recoverTree(root);

    cout << "\nInorder Traversal of the fixed tree \n";
    obj.printInorder(root);

    return 0;
}