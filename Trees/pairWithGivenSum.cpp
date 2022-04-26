#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:
    // root : the root Node of the given BST

    int isPairPresent(struct Node *root, int targetSum)
    {
        // Write your code here
        set<int> s;
        return (twoSumBSTUtil(root, targetSum, s));
    }

    bool twoSumBSTUtil(Node *root, int targetSum, set<int> &s)
    {
        if (root == NULL)
            return 0;
        if (twoSumBSTUtil(root->left, targetSum, s) == true)
            return 1;
        if (s.find(targetSum - root->data) != s.end())
            return 1;
        else
            s.insert(root->data);
        return twoSumBSTUtil(root->right, targetSum, s);
    }
    Node *insert(Node *root, int key)
    {
        if (root == NULL)
        {
            return new Node(key);
        }

        if (key < root->data)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);
        return root;
    }
};

int main()
{

    // Function call
    Solution obj;
    Node *root = NULL;
    root = obj.insert(root, 15);
    root = obj.insert(root, 10);
    root = obj.insert(root, 20);
    root = obj.insert(root, 8);
    root = obj.insert(root, 12);
    root = obj.insert(root, 16);
    root = obj.insert(root, 25);
    root = obj.insert(root, 10);
    int targetSum = 28;
    cout << obj.isPairPresent(root, targetSum);

    return 0;
}