#include <iostream>
#include <queue>
#include <map>
#include <algorithm>

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

class Traversal
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> output;
        if (root == NULL)
            return output;

        queue<pair<TreeNode *, pair<int, int>>> q; // Node, level, distance
        q.push({root, {0, 0}});

        map<int, vector<int>> mapp;
        while (q.empty() == false)
        {
            vector<pair<int, int>> v2; // Node data, dist
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front().first;
                int level = q.front().second.first;
                int distance = q.front().second.second;
                q.pop();
                v2.push_back({curr->val, distance});
                if (curr->left != NULL)
                    q.push({curr->left, {level + 1, distance - 1}});
                if (curr->right != NULL)
                    q.push({curr->right, {level + 1, distance + 1}});
            }
            sort(v2.begin(), v2.end());
            for (auto it : v2)
                mapp[it.second].push_back(it.first);
        }
        for (auto it : mapp)
        {
            output.push_back(it.second);
        }
        return output;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    Traversal obj;
    vector<vector<int>> ans = obj.verticalTraversal(root);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";
    return 0;
}
