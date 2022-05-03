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
    vector<int> v;
    vector<int> Serialize(Node *root)
    {
        if (root == NULL)
        {
            v.push_back(-1);
            return v;
        }
        v.push_back(root->data);
        Serialize(root->left);
        Serialize(root->right);
        return v;
    }

    int index = 0;
    Node *DeSerialize(vector<int> A)
    {
        if (index == A.size())
            return NULL;
        int val = A[index];
        index++;
        if (val == -1)
            return NULL;
        Node *root = new Node(val);
        root->left = DeSerialize(A);
        root->right = DeSerialize(A);
        return root;
    }
};
