#include <iostream>
using namespace std;
int nums[10005];
int main() // 寻找最大和子序列
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> nums[i];
    }
    int maxs = 0, st = nums[1], ed = nums[n];
    for (int i = 1; i <= n; i++)
    {
        if (nums[i] == 0)
        {
            st = nums[i], ed = nums[i];
            break;
        }
    }
    int now = 0, nst = nums[1];
    for (int i = 1; i <= n; i++)
    {
        if (now + nums[i] > 0)
        {
            now += nums[i];
            if (now > maxs)
            {
                maxs = now, st = nst, ed = nums[i];
            }
        }
        else
        {
            now = 0, nst = nums[i + 1];
        }
    }
    cout << maxs << " " << st << " " << ed;
    return 0;
}