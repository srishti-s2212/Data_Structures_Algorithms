#include <iostream>
#include <queue>

using namespace std;

class MedianFinder
{
public:
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;

    void addNum(int num)
    {
        if (maxh.size() == 0 || num < maxh.top())
            maxh.push(num);
        else
            minh.push(num);
        BalanceHeap();
    }
    void BalanceHeap()
    {
        if (maxh.size() > minh.size() + 1)
        {
            minh.push(maxh.top());
            maxh.pop();
        }
        if (minh.size() > maxh.size() + 1)
        {
            maxh.push(minh.top());
            minh.pop();
        }
    }

    double findMedian()
    {
        if (maxh.size() == minh.size())
            return ((maxh.top() + minh.top()) / 2.0);
        if (maxh.size() > minh.size())
            return maxh.top();
        else
            return minh.top();
    }
};

int main()
{
    int arr[] = {5, 15, 1, 3, 2, 8, 7, 9, 10, 6, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    MedianFinder *obj = new MedianFinder();
    for (int i = 0; i < n; i++)
        obj->addNum(arr[i]);
    cout << obj->findMedian() << endl;
}