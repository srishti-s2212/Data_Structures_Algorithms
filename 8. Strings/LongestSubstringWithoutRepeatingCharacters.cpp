#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution
{
public:
    // O(n^2)
    //     int lengthOfLongestSubstring(string s) {

    //         int n=s.size();
    //         int res=0;
    //         for(int i=0; i<n; i++)
    //         {
    //             vector<bool> visited(256);
    //             for(int j=i; j<n; j++)
    //             {
    //                 if(visited[s[j]]==false)
    //                 {
    //                     res=max(res, j-i+1);
    //                     visited[s[j]]=true;
    //                 }
    //                 else
    //                     break;
    //             }
    //         }
    //         return res;
    //     }
    // More Efficient: O(n)
    int lengthOfLongestSubstring(string s)
    {

        int n = s.size();
        int res = 0;
        int i = 0;
        vector<int> prev(256, -1);
        for (int j = 0; j < n; j++)
        {
            i = max(i, prev[s[j]] + 1);
            res = max(res, j - i + 1);
            prev[s[j]] = j;
        }
        return res;
    }
};

int main()
{
    Solution obj;
    cout << "Enter string: ";
    string str;
    cin >> str;
    cout << "Leftmost Non-Repeating character index: " << obj.lengthOfLongestSubstring(str);
    return 0;
}
