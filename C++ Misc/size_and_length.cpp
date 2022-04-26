// CPP program to illustrate
// Different methods to find length
// of a string
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main()
{
    // String obj
    string str = "GeeksforGeeks";

    // 1. size of string object using size() method
    cout << str.size() << endl;

    // 2. size of string object using length method
    cout << str.length() << endl;

    vector<vector<char>> grid = {{0, 1}, {1, 0}, {1, 1}, {1, 0}};
    cout << "Grid Row Size: " << grid.size() << endl;
    // length() does not work on vector of char type
    // cout << "Grid Length " << grid[0].length()<<endl;//Error
    cout << "Grid Col Size: " << grid[0].size() << endl;

    // vector<vector<int>> grid2 = {{0, 1}, {1, 0}, {1, 1}, {1, 0}};
    // cout << "Grid2(int) Row Size: " << grid2.size() << endl;
    // cout << "Grid2(int) Col Size: " << grid2[0].size() << endl;
    // // cout << "Grid2 Length " << grid2[0].length() << endl;

    vector<string> strvector = {"abc", "efg", "hij", "klm"};
    cout << "Vector of string size: " << strvector.size() << endl;
    // cout << "Vector of string length: " << strvector.length() << endl;

    cout << "Vector of string length: " << strvector[0].size();
    return 0;
}
