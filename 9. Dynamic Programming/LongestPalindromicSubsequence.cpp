#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class Solution
{
public:
    int longestPalindromeSubseq(string a)
    {
        // LPS(a)=LCS(a, reverse(a));
        string a1 = a;
        reverse(a.begin(), a.end());
        int ans = longestCommonSubsequence(a1, a);
        return ans;
    }

    int longestCommonSubsequence(string a, string b)
    {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> t(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    t[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (a[i - 1] == b[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
            }
        }
        return t[n][m];
    }
};

int main()
{
    string a = "abcbaea";
    Solution obj;
    cout << "Longest Palindromic Subsequence length: "
         << obj.longestPalindromeSubseq(a);
    return 0;
}