#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &arr)
    {
        int maxEnding = arr[0], res = arr[0];
        int n = arr.size();
        for (int i = 1; i < n; i++)
        {
            maxEnding = max(maxEnding + arr[i], arr[i]);
            res = max(res, maxEnding);
        }
        return res;
    }
};

int main()
{

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution obj;
    int ans = obj.maxSubArray(arr);
    cout << "\nAnswer is: " << ans;
    return 0;
}
