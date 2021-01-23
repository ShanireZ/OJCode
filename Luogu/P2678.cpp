#include <iostream>
#include <algorithm>
using namespace std;
int s[50005], a[50005];
int l, n, m;
bool check(int lmt)
{
    int cnt = 0, cur = 0;
    for (int i = 1; i <= n + 1; i++)
    {
        cur += s[i];
        if (cur < lmt)
        {
            cnt++;
        }
        else
        {
            cur = 0;
        }
    }
    if (cnt > m)
    {
        return false;
    }
    return true;
}
int main()
{
    cin >> l >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[n + 1] = l;
    for (int i = 1; i <= n + 1; i++)
    {
        s[i] = a[i] - a[i - 1];
    }
    int L = 0, R = l;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (check(mid) == false)
        {
            R = mid - 1;
        }
        else
        {
            L = mid + 1;
        }
    }
    cout << R;
    return 0;
}