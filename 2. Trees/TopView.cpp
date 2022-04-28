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
class View
{
public:
    vector<int> topView(Node *root)
    {
        vector<int> v;
        if (root == NULL)
            return v;

        queue<pair<Node *, int>> q;
        q.push({root, 0});

        map<int, int> mp;
        mp[0] = root->data;
        while (q.empty() == false)
        {
            Node *curr = q.front().first;
            int dist = q.front().second;
            q.pop();
            if (mp.find(dist) == mp.end())
                mp[dist] = curr->data;
            if (curr->left != NULL)
                q.push({curr->left, dist - 1});
            if (curr->right != NULL)
                q.push({curr->right, dist + 1});
        }
        for (auto it : mp)
            v.push_back(it.second);
        return v;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->left->right = new Node(5);
    View obj;
    vector<int> ans = obj.topView(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}