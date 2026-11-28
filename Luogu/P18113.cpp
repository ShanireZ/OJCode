#include <algorithm>
#include <iostream>
using namespace std;
int n, k, pos, a[200005], prim[200005];
void check(int st)
{
    int v = 2, x = st;
    while (x > 1 && v * v <= st)
    {
        int ok = 0;
        while (x % v == 0)
        {
            x /= v, ok = 1;
        }
        if (ok)
        {
            prim[++pos] = v;
        }
        v++;
    }
    if (x > 1)
    {
        prim[++pos] = x;
    }
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    check(a[1]);
    check(a[1] - 1);
    sort(prim + 1, prim + pos + 1);
    for (int i = pos; i >= 1; i--)
    {
        if (prim[i] == prim[i + 1])
        {
            continue;
        }
        int cnt = 0, ok = 1, v = prim[i];
        for (int j = 1; j <= n; j++)
        {
            if (a[j] % v && (a[j] - 1) % v)
            {
                ok = 0;
                break;
            }
            if (a[j] % v && (a[j] - 1) % v == 0)
            {
                cnt++;
            }
        }
        if (ok && cnt <= k)
        {
            cout << v << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}