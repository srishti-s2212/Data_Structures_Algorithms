#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxRainWaterTrapped(vector<int> arr)
    {
        const int n = 6;
        int lmax[n];
        int rmax[n];
        lmax[0] = arr[0];
        rmax[n - 1] = arr[n - 1];

        for (int i = 1; i < n; i++)
        {
            lmax[i] = max(lmax[i - 1], arr[i]);
        }
        // right max array
        for (int i = n - 2; i >= 0; i--)
            rmax[i] = max(rmax[i + 1], arr[i]);

        int ans = 0;
        for (int i = 0; i < n - 1; i++)
            ans = ans + (min(lmax[i], rmax[i]) - arr[i]);
        return ans;
    }
};

int main()
{
    // int arr[] = {3, 0, 0, 2, 0, 4};
    // int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> arr = {3, 0, 0, 2, 0, 4};
    Solution obj;
    int ans = obj.maxRainWaterTrapped(arr);
    cout << "\nAnswer is: " << ans;
    return 0;
}