#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int nums[105];
int left_m[105];
int right_m[105];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    fill_n(left_m, n + 1, 1);
    fill_n(right_m, n + 1, 1);
    for (int i = 1; i <= n; i++) //求出以1-n结束时从左向右排列的最长上升子序列长度
    {
        for (int j = 1; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                left_m[i] = max(left_m[i], left_m[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) //求出以n-1结束时从右向左排列的最长上升子序列长度
    {
        for (int j = n; j > i; j--)
        {
            if (nums[i] > nums[j])
            {
                right_m[i] = max(right_m[i], right_m[j] + 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) //枚举中间点，找到最大值
    {
        ans = max(ans, left_m[i] + right_m[i] - 1); //中间点多统计一次，需要减一
    }
    cout << n - ans;
    return 0;
}