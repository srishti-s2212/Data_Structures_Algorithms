#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int rowWithMax1s(int mat[4][4], int R, int C)
    {
        int j, max_row_index = 0;
        j = C - 1;

        for (int i = 0; i < R; i++)
        {
            // Move left until a 0 is found
            bool flag = false; // to check whether a row has more 1's than previous
            while (j >= 0 && mat[i][j] == 1)
            {
                j = j - 1;   // Update the index of leftmost 1
                             // seen so far
                flag = true; // present row has more 1's than previous
            }
            // if the present row has more 1's than previous
            if (flag)
            {
                max_row_index = i; // Update max_row_index
            }
        }
        if (max_row_index == 0 && mat[0][C - 1] == 0)
            return -1;
        return max_row_index;
    }
};

int main()
{
    int mat[4][4] = {{0, 0, 0, 1},
                     {0, 1, 1, 1},
                     {1, 1, 1, 1},
                     {0, 0, 0, 0}};

    Solution obj;
    cout << "Index of row with maximum 1s is " << obj.rowWithMax1s(mat, 4, 4);

    return 0;
}