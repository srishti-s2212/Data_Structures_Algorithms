#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &arr1, vector<int> &arr2)
    {
        // My Understanding
        // Step 1: Merge array and partition Array into 2 segments such that all are left array
        // element less than right array elements
        // Step 2: We have cut 1 and cut 2
        // Step 3: We can say that max of array 1 and min of array 2 will form median
        // Step 4: condition l1 <r2, l2<r1

        int n1 = arr1.size();
        int n2 = arr2.size();
        if (n2 < n1)
            findMedianSortedArrays(arr2, arr1);
        int lo = 0;
        int hi = n1;

        while (lo <= hi)
        {
            // Initialize the cuts or partitions
            int cut1 = lo + (hi - lo) / 2;
            // Total required - already present
            int cut2 = ((n1 + n2) / 2) - cut1;

            // Initialize l1,l2,r1,r2
            int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
            int r1 = (cut1 == n1) ? INT_MAX : arr1[cut1];
            int r2 = (cut2 == n2) ? INT_MAX : arr2[cut2];

            // Shift element to the left
            if (l1 > r2)
                hi = cut1 - 1;
            else if (l2 > r1)
                lo = cut1 + 1;
            else
            {
                // Check for even length
                if ((n1 + n2) % 2 == 0)
                    return (double)(max(l1, l2) + min(r1, r2)) / 2;
                else
                    return (double)(min(r1, r2));
            }
        }
        return 0.0;
    }
};

int main()
{
    vector<int> v1 = {1, 5, 10, 15, 20};
    vector<int> v2 = {2, 4, 9, 12, 14};
    Solution obj;
    cout << "Median is: " << obj.findMedianSortedArrays(v1, v2);
    return 0;
}