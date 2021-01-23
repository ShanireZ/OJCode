#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int l, n, k, a[100005];
bool check(int lmt)
{
    int cnt = 0;
    for (int i = 2; i <= n; i++)
    {
        double d = a[i] - a[i - 1];
        if (d > lmt)
        {
            cnt += ceil(d / lmt) - 1;
        }
    }
    if (cnt <= k)
    {
        return true;
    }
    return false;
}
int main()
{
    cin >> l >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int L = 0, R = l;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (check(mid))
        {
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    cout << L;
    return 0;
}