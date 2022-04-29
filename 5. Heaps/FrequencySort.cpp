#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> frequencySort(int arr[], int n)
    {

        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minh;

        unordered_map<int, int> mp;
        vector<int> v;
        for (int i = 0; i < n; i++)
            mp[arr[i]]++;

        for (auto it : mp)
        {
            minh.push({(it.second), it.first});
        }
        while (minh.size() > 0)
        {
            int freq = minh.top().first;
            int elem = minh.top().second;
            for (int i = 0; i < freq; i++)
                v.push_back(elem);
            minh.pop();
        }
        return v;
    }
};

int main()
{
    int arr[] = {1, 1, 2, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    vector<int> ans = obj.frequencySort(arr, n);
    vector<int> v = {1, 1, 2, 2, 2, 3};
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(3);
    // vector<int> ans = obj.frequencySort(arr);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i];
    return 0;
}