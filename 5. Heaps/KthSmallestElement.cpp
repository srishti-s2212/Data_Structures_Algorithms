#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    int findKthSmallest(vector<int> arr, int k)
    {
        priority_queue<int> maxh;
        int n = arr.size();
        for (int i = 0; i <= n; i++)
        {
            maxh.push(arr[i]);
            if (maxh.size() > k)
                maxh.pop();
        }
        return maxh.top();
    }
};

int main()
{
    Solution obj;
    vector<int> v = {5, 1, 7, 3, 2, 4};
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(3);
    int k = 3;
    cout << obj.findKthSmallest(v, k);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i];
    return 0;
}