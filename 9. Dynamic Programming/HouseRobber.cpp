#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int houseRobber(vector<int> arr)
    {
        const int n = arr.size();

        // Base Condition
        if (n == 1)
            return arr[0];
        if (n == 2)
            return max(arr[0], arr[1]);
        vector<int> dp(n);
        dp[n - 1] = arr[n - 1];
        dp[n - 2] = arr[n - 2];
        int maxtill = dp[n - 1];
        for (int i = n - 3; i >= 0; i--)
        {
            dp[i] = arr[i] + maxtill;
            maxtill = max(maxtill, dp[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[i]);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> arr = {1, 2, 3, 1};
    cout << obj.houseRobber(arr);
    return 0;
}
