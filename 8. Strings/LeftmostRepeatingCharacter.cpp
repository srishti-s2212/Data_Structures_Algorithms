#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int leftmostRepeating(string str)
    {
        bool visited[26] = {false};
        int n = str.size();
        if (n == 1)
            return false;
        int ans = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (visited[str[i]] == false)
                visited[str[i]] = true;
            else
                ans = i;
        }
        return ans;
    }
};
int main()
{
    Solution obj;
    cout << "Enter string: ";
    string str;
    cin >> str;
    cout << "Leftmost Repeating character index: " << obj.leftmostRepeating(str);
    return 0;
}
