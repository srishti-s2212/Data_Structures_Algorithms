#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string str)
    {
        int visited[256] = {0};
        for (int i = 0; i < str.size(); i++)
        {
            visited[str[i]]++;
        }
        for (int i = 0; i < str.size(); i++)
            if (visited[str[i]] == 1)
                return i;
        return -1;
    }
};
int main()
{
    Solution obj;
    cout << "Enter string: ";
    string str;
    cin >> str;
    cout << "Leftmost Non-Repeating character index: " << obj.firstUniqChar(str);
    return 0;
}
