#include <iostream>

using namespace std;

class Solution
{
public:
    int AllicateminPages(int arr[], int n, int m)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum = sum + arr[i];
        int start = 0;
        int end = sum;
        int result;
        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (isValid(arr, n, m, mid))
            {
                end = mid - 1;
                result = mid;
            }
            else
                start = mid + 1;
        }
        return result;
    }

    bool isValid(int arr[], int n, int m, int mid)
    {
        int curr_sum = 0;
        int studentsRequired = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > mid)
                return false;
            else if (arr[i] + curr_sum > mid)
            {
                curr_sum = arr[i];
                studentsRequired++;
                if (studentsRequired > m)
                    return false;
            }
            else
                curr_sum = curr_sum + arr[i];
        }
        return true;
    }
};

int main()
{
    Solution obj;
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; // No. of students

    cout << "Minimum number of pages = " << obj.AllicateminPages(arr, n, m) << endl;
    return 0;
}