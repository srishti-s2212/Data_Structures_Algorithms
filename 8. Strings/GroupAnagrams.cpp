#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        // O(nmlogm)
        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < strs.size(); i++)
        {
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    // vector<string> strs;
    // vector<string> strs = {"cat", "dog", "ogd", "god", "atc"};
    vector<string> arr;
    arr.push_back("geeksquiz");
    arr.push_back("geeksforgeeks");
    arr.push_back("abcd");
    arr.push_back("forgeeksgeeks");
    arr.push_back("zuiqkeegs");
    arr.push_back("cat");
    arr.push_back("act");
    arr.push_back("tca");
    // cout << "\nEnter string: ";
    // string temp;
    // getline(cin, temp);
    // strs.push_back(temp);
    vector<vector<string>> ans = obj.groupAnagrams(arr);
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << "[";
    //     for (int j = 0; i < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << ", ";
    //     }
    //     cout << "]";
    // }

    for (auto it : ans)
    {
        cout << "[";
        for (auto x : it)
        {
            cout << x << " ";
        }
        cout << "]";
    }
    return 0;
}
