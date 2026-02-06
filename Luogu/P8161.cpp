#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
long long n, m, a[300005], b[300005];
bool check(long long tar)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
        {
            long long x = min((tar + a[i] - 1) / a[i], m);
            res += x;
            if (tar - x * a[i] > 0)
            {
                res += (tar - x * a[i] + b[i] - 1) / b[i];
            }
        }
        else
        {
            res += (tar + b[i] - 1) / b[i];
        }
        if (res > m * n)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    long long l = 1, r = 2e18;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        check(mid) ? l = mid + 1 : r = mid - 1;
    }
    cout << r << endl;
    return 0;
}