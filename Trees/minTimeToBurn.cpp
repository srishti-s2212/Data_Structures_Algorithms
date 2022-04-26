#include <iostream>
#include <queue>
#include <map>

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
    // Func create NodetoParentMapping and traverses to target node. Returns target Node
    Node *createMapping(Node *root, map<Node *, Node *> &nodeToParent, int target)
    {
        Node *res = NULL;
        queue<Node *> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->data == target)
                res = curr;
            if (curr->left != NULL)
            {
                nodeToParent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                nodeToParent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return res;
    }

    int minTimeUtil(Node *root, map<Node *, Node *> &nodeToParent)
    {
        map<Node *, bool> visited;
        visited[root] = true;
        int ans = 0;

        queue<Node *> q;
        q.push(root);

        while (q.empty() == false)
        {
            bool flag = false;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left != NULL && visited[curr->left] == false)
                {
                    q.push(curr->left);
                    flag = true;
                    visited[curr->left] = true;
                }
                if (curr->right != NULL && visited[curr->right] == false)
                {
                    q.push(curr->right);
                    flag = true;
                    visited[curr->right] = true;
                }
                if (nodeToParent[curr] != NULL && visited[nodeToParent[curr]] == false)
                {
                    q.push(nodeToParent[curr]);
                    flag = true;
                    visited[nodeToParent[curr]] = true;
                }
            }
            if (flag == true)
                ans++;
        }
        return ans;
    }

    int minTime(Node *root, int target)
    {
        map<Node *, Node *> nodeToParent;
        Node *targetNode = createMapping(root, nodeToParent, target);
        int ans = minTimeUtil(targetNode, nodeToParent);
        cout << "Min time to burn is: " << ans;
        return ans;
    }
};
int main()
{
    Node *root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(13);

    root->right->left = new Node(14);
    root->right->right = new Node(15);

    root->right->left->left = new Node(21);
    root->right->left->right = new Node(22);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);
    int targetNode = 14;

    // Function call
    Solution obj;
    obj.minTime(root, targetNode);

    return 0;
}