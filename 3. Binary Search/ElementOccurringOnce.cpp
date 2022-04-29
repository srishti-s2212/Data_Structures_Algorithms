#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            // or low + (high-low)/2

            // Corner case: mid=0 || mid=n-1
            if ((mid == 0 && arr[mid] != arr[mid + 1]) || (mid == n - 1 && arr[mid] != arr[mid - 1]))
                return arr[mid];
            if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
                return arr[mid];
            if (mid % 2 != 0)
            {
                if (arr[mid] == arr[mid - 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if (arr[mid] == arr[mid + 1])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};
int main()
{
    vector<int> v = {1, 1, 2, 2, 3, 4, 4, 5, 5};
    Solution obj;
    cout << "Element occurring once is: " << obj.singleNonDuplicate(v);
    return 0;
}