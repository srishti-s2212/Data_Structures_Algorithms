#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        int n = s.size();
        priority_queue<pair<int, char>> maxh;
        map<char, int> mp;
        for (int i = 0; i < n; i++)
            mp[s[i]]++;

        for (auto it : mp)
        {
            maxh.push({it.second, it.first});
        }
        string ans;
        while (maxh.size() > 0)
        {
            int freq = maxh.top().first;
            char elem = maxh.top().second;
            for (int i = 0; i < freq; i++)
                ans = ans + elem;
            maxh.pop();
        }
        return ans;
    }

    // Using MinHeap:
    string frequencySort(string s)
    {
        string ans = "";
        map<char, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }
        map<char, int>::iterator it;
        for (it = mp.begin(); it != mp.end(); it++)
        {
            pq.push({it->second, it->first});
        }
        while (!pq.empty())
        {
            pair<int, int> x = pq.top();
            pq.pop();
            while (x.first--)
                ans += x.second;
        }
        return ans;
    }
};

int main()
{
    string s = "tree";
    Solution obj;
    cout << obj.frequencySort(s);
    return 0;
}