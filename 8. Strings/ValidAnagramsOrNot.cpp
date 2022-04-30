#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isAnagram(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        // Base Condition
        if (n != m)
            return false;

        int count[26] = {0};
        for (int i = 0; i < n; i++)
        {
            count[str1[i] - 'a']++;
            count[str2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (count[i] != 0)
                return false;
        return true;
    }
};

int main()
{
    Solution obj;
    // string str1="cat";
    // string str2="tac";
    string str1, str2;
    cout << "\nEnter string1: ";
    cin >> str1;
    cout << "\nEnter string2: ";
    cin >> str2;

    cout << "\nAnswer: " << obj.isAnagram(str1, str2);
    return 0;
}