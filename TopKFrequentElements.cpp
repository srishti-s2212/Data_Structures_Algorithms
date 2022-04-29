#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    void TopKFrequent(int arr[], int n, int k)
    {
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minh;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        for (auto it : mp)
        {
            minh.push({it.second, it.first});
            if (minh.size() > k)
                minh.pop();
        }
        while (minh.size() > 0)
        {
            cout << minh.top().second << " ";
            minh.pop();
        }
    }
};

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    Solution obj;
    obj.TopKFrequent(arr, n, k);
    vector<int> v = {1, 1, 2, 2, 2, 3};
    return 0;
}