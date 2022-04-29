#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {

        int i, low, high, mid, n = nums.size();
        low = 0;
        high = n - 1;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[low] <= nums[mid])
            {
                if (target > nums[mid] || target < nums[low])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if (target < nums[mid] || target > nums[high])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return -1;
    }

    // int search(vector<int> nums, int target){

    //     int n=nums.size();
    //     int l=0, h=n-1;
    //     int pivotIndex = findPivot(nums, l, h);
    //     //cout<<nums[pivotIndex];
    //     if(nums[pivotIndex]==target)
    //         return pivotIndex;
    //     if(pivotIndex == -1)
    //         return BinarySearch(nums, l, h, target); //Array not rotated
    //     if(target >= nums[l])
    //         return BinarySearch(nums, l, pivotIndex-1, target);
    //     else
    //     return BinarySearch(nums, pivotIndex+1, h, target);
    // }
    // int BinarySearch(vector<int> nums, int low, int high, int target)
    // {
    //     while(low<=high)
    //     {
    //         int mid=(low+high)/2;
    //         cout<<"Low: "<<low<<" ";
    //         cout<<"Mid: "<<mid<<" ";
    //         cout<<"Elem: "<<nums[mid]<<endl;
    //         if(nums[mid]==target)
    //         {
    //           // cout<<"Found"<<mid;
    //             return mid;
    //         }
    //         if(target>nums[mid])
    //             low=mid+1;
    //         else
    //             high=mid-1;
    //     }
    //     cout<<"Binary Search result:"<<-1;
    //     return -1;
    // }
    // int findPivot(vector<int> nums, int low, int high)
    // {
    //     if(low==high)
    //         return low;
    //     if(high<low)
    //         return -1;
    //     while(low<=high)
    //     {
    //         int mid=(low+high)/2;
    //         if( nums[mid]>nums[mid+1])
    //             return mid;
    //         else if( nums[mid]<nums[mid-1])
    //             return mid-1;
    //         else
    //         {
    //             if(nums[mid]>nums[high])
    //             low=mid+1;
    //             else
    //             high=mid-1;
    //         }
    //     }
    //     return -1;
    // }
};
int main()
{
    // int arr[] = {1, 1, 2, 2, 2, 3};
    // int n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    // v.push_back(1);
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(2);
    // v.push_back(3);
    int ans = obj.search(v, 0);
    return 0;
}
