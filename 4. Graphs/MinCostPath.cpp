#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    bool isSafe(int row, int col, int n)
    {
        if (row < 0 || col < 0 || row > n - 1 || col > n - 1)
            return 0;
        return 1;
    }
    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        q.push({grid[0][0], {0, 0}});

        dist[0][0] = grid[0][0];
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        while (!q.empty())
        {
            int distance = q.top().first;
            int row = q.top().second.first;
            int col = q.top().second.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                if (isSafe(row + dx[i], col + dy[i], n))
                {
                    if (dist[row + dx[i]][col + dy[i]] > distance + grid[row + dx[i]][col + dy[i]])
                    {
                        dist[row + dx[i]][col + dy[i]] = distance + grid[row + dx[i]][col + dy[i]];
                        q.push({dist[row + dx[i]][col + dy[i]], {row + dx[i], col + dy[i]}});
                    }
                }
            }
        }
        return dist[n - 1][n - 1];
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
    cout << "Answer:" << obj.minimumCostPath(grid);
    return 0;
}