#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Function to find whether a path exists from the source to destination.
    //  bool is_Possible(vector<vector<int>>& grid)
    //  {
    //      //code here
    //  }

    bool is_Possible(vector<vector<int>> &g)
    {
        // code here
        int ans = 0;
        for (int i = 0; i < g.size(); i++)
        {
            for (int j = 0; j < g[0].size(); j++)
            {
                if (g[i][j] == 1 || g[i][j] == 2)
                {
                    dfs(g, i, j, ans);
                    return ans == 2;
                }
            }
        }
        return 0;
    }

    void dfs(vector<vector<int>> &g, int i, int j, int &ans)
    {
        if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] == 0)
            return;
        if (g[i][j] == 1 || g[i][j] == 2)
            ans++;
        g[i][j] = 0;
        dfs(g, i + 1, j, ans);
        dfs(g, i - 1, j, ans);
        dfs(g, i, j + 1, ans);
        dfs(g, i, j - 1, ans);
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> grid;
    for (int i = 0; i < 2; i++)
    {
        cout << "Enter " << i << " row data:" << endl;
        vector<int> v2;
        for (int j = 0; j < 2; j++)
        {
            int value = 0;
            cin >> value;
            v2.push_back(value);
        }
        grid.push_back(v2);
        cout << endl;
    }
    cout << "Answer:" << obj.is_Possible(grid);
    return 0;
}