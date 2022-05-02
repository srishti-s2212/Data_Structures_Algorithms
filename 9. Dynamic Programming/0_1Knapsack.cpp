#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int knapsack(int Wt[], int val[], int W, const int n)
    {
        // vector<vector<int>> t(n + 1, vector<int>(W, 0));
        // Works
        //  vector<vector<int>> t(n, vector<int>(W + 1, 0));
        //  // Base Condition
        //  for (int i = Wt[0]; i <= W; i++)
        //  {
        //      t[0][i] = val[0];
        //  }

        // for (int i = 1; i < n; i++)
        // {
        //     for (int j = 1; j <= W; j++)
        //     {
        //         if (Wt[i - 1] < j)
        //             t[i][j] = max(val[i - 1] + t[i - 1][j - Wt[i - 1]], t[i - 1][j]);

        //         else
        //             t[i][j] = t[i - 1][j];
        //     }
        // }
        // return t[n - 1][W];

        vector<vector<int>> dp(n + 1, vector<int>(W + 1));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                if (Wt[i - 1] <= j)
                    dp[i][j] = max(
                        dp[i - 1][j],
                        dp[i - 1][j - Wt[i - 1]] + val[i - 1]);
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][W];
    }
};

int main()
{

    int val[] = {60, 100, 120};
    int Wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    Solution obj;

    cout << "\n\nAnswer is: " << obj.knapsack(Wt, val, W, n) << endl;
    return 0;
}
