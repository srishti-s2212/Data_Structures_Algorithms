#include <iostream>
#include <queue>

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

class View
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> v;
        if (root == NULL)
            return v;
        queue<TreeNode *> q;
        q.push(root);
        while (q.empty() == false)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left != NULL)
                    q.push(curr->left);
                if (curr->right != NULL)
                    q.push(curr->right);
                if (i == size - 1)
                    v.push_back(curr->val);
            }
        }
        return v;
    }
    //     vector<int> rightSideView(TreeNode* root)
    //     {
    //         vector<int> v;
    //         if(root == NULL)
    //             return v;
    //         return (rightSideUtil(root, v, 0));
    //     }

    //     vector<int> rightSideUtil(TreeNode* root, vector<int> &v, int level)
    //     {
    //         if(root == NULL)
    //             return v;
    //         if(v.size() == level)
    //             v.push_back(root->val);
    //         rightSideUtil(root->right, v, level+1);
    //         rightSideUtil(root->left, v, level+1);
    //         return v;
    //     }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    View obj;
    vector<int> ans = obj.rightSideView(root);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}