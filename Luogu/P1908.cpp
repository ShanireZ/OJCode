#include <iostream>
using namespace std;
int nums[500000], temp[500000];
long long total;
void mergesort(int start, int end) //start开始下标，end结束下标
{
    if (end == start) //仅剩1个元素，停止分组返回上层，上层至少
    {
        return;
    }
    int mid = (start + end) / 2;
    mergesort(start, mid);   //不断分组，直到本次分组仅剩1个元素时继续下条语句
    mergesort(mid + 1, end); //不断分组，直到本次分组仅剩1个元素时继续下方的归并
    int i, j, pos;
    for (i = start, j = mid + 1, pos = 0; i <= mid && j <= end;)
    {
        if (nums[i] <= nums[j])
        {
            temp[pos++] = nums[i++];
        }
        else
        {
            temp[pos++] = nums[j++];
            total += mid - i + 1;
        }
    }
    while (i <= mid)
    {
        temp[pos++] = nums[i++];
    }
    while (j <= end)
    {
        temp[pos++] = nums[j++];
    }
    memcpy(nums + start, temp, sizeof(int) * pos);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    mergesort(0, n - 1);
    cout << total;
    return 0;
}