#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    long long minCost(long long arr[], long long n)
    {

        priority_queue<long long, vector<long long>, greater<long long>> minh;
        for (int i = 0; i < n; i++)
            minh.push(arr[i]);
        long long cost = 0;
        while (minh.size() > 1)
        {
            long long a = minh.top();
            minh.pop();
            long long b = minh.top();
            minh.pop();
            long long sum = a + b;
            cost = cost + sum;
            minh.push(sum);
        }
        return cost;
    }
};

int main()
{
    long long arr[] = {4, 3, 2, 6};
    long long n = sizeof(arr) / sizeof(arr[0]);
    Solution obj;
    cout << obj.minCost(arr, n);
}