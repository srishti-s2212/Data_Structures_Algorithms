#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {

        //     priority_queue<int, vector<int>, greater<int>> minh;
        //     for(int i=0;i<nums.size();i++)
        //     {
        //         minh.push(nums[i]);
        //         while(minh.size()>k)
        //         {
        //             minh.pop();
        //         }
        //     }
        //     return minh.top();
        // }

        priority_queue<int> maxh;
        for (int i = 0; i < nums.size(); i++)
            maxh.push(nums[i]);
        int count = 1;
        while (count != k)
        {
            maxh.pop();
            count++;
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
    cout << obj.findKthLargest(v, k);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i];
    return 0;
}