#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
long long T, n, k, pos, a[100005], b[100005];
bool check(long long x)
{
    long long t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= x)
        {
            t += (a[i] - x) / b[i] + 1;
        }
    }
    return t > k;
}
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> b[i];
        }
        long long l = 1, r = 1e9, res = 0;
        while (l <= r) // 二分最小单次挖掘量
        {
            long long mid = (l + r) / 2;
            check(mid) ? l = mid + 1 : r = mid - 1; // 只要次数够用就可尝试更小的极限
        }
        pos = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] >= l)
            {
                long long t = (a[i] - l) / b[i] + 1;
                long long ed = a[i] - (t - 1) * b[i];
                res += (a[i] + ed) * t / 2, k -= t;
            }
        }
        res += (l - 1) * k;
        cout << res << endl;
    }
    return 0;
}