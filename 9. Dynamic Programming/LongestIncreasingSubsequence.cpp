#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestIncreasingSubseq(vector<int> arr)
    {
        int n = arr.size();
        vector<int> dp(n);
        dp[0] = arr[0];
        int len = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] > dp[len - 1])
            {
                dp[len] = arr[i];
                len++;
            }
            else
            {
                int index = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
                dp[index] = arr[i];
            }
        }
        return len;

        // // Leetcode Works: -
        // int n = arr.size();
        // vector<int> temp;
        // temp.push_back(arr[0]);
        // int len = 1;
        // for (int i = 1; i < n; i++)
        // {
        //     if (arr[i] > temp.back())
        //     {
        //         temp.push_back(arr[i]);
        //         len++;
        //     }
        //     else
        //     {
        //         int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
        //         temp[index] = arr[i];
        //     }
        // }
        // return len;
    }
};

int main()
{
    vector<int> arr = {10, 80, 100, 150, 12, 14, 110, 155};
    Solution obj;
    cout << obj.longestIncreasingSubseq(arr);
    return 0;
}