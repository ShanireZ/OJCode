#include <iostream>
using namespace std;
int m, k, a[505], cut[505];
int main()
{
    cin >> m >> k;
    for (int i = 1; i <= m; ++i)
    {
        cin >> a[i];
    }
    int L = 1, R = 1e9;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        int cnt = 0, now = 0;
        for (int i = 1; i <= m; i++)
        {
            if (now + a[i] <= mid)
            {
                now += a[i];
            }
            else
            {
                cnt++, now = a[i];
            }
        }
        cnt++;
        if (cnt > k)
        {
            L = mid + 1;
        }
        else
        {
            R = mid - 1;
        }
    }
    int now = 0;
    for (int i = m; i >= 1; i--)
    {
        if (now + a[i] <= L)
        {
            now += a[i];
        }
        else
        {
            cut[i] = 1, now = a[i];
        }
    }
    cut[0] = cut[m] = 1;
    for (int i = 1; i <= m; i++)
    {
        if (cut[i - 1])
        {
            cout << i << " ";
        }
        if (cut[i])
        {
            cout << i << endl;
        }
    }
    return 0;
}