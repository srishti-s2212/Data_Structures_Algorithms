#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    bool ParenthesisChecker(string str)
    {
        int n = str.length();
        stack<char> st;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '(' || str[i] == '{' || str[i] == '[')
                st.push(str[i]);
            else
            {
                if (st.empty() == true)
                    return false;
                else if (isValid(st.top(), str[i]) == true)
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty() == true)
            return true;
        return false;
    }

    bool isValid(char a, char b)
    {
        if (a == '(' && b == ')' ||
            a == '{' && b == '}' ||
            a == '[' && b == ']')
            return true;
        return false;
    }
};

int main()
{
    Solution obj;
    string str;
    cout << "Please enter input: ";
    // cin >> str; //Please Note: cin considers space as terminating character
    // if input has space but parenthesis sequence is correct, our out would be 0
    // cin stops taking input as soon as space found

    getline(cin, str);
    cout << "Answer is: " << obj.ParenthesisChecker(str);
}