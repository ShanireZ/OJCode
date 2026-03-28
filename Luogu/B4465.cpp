#include <algorithm>
#include <iostream>
using namespace std;
long long n, k, a[100005], b[100005];
bool check(long long x)
{
    long long now = k;
    for (int i = 1; i <= n && now >= 0; i++)
    {
        if (a[i] * x > b[i])
        {
            now -= a[i] * x - b[i]; // 有可能减爆longlong
        }
    }
    return now >= 0;
}
int main()
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
    long long l = 0, r = 2e9;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        check(mid) ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}