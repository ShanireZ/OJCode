#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int h[100005], c[100005], ls[100005], l[100005], n, sz, ans;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= n)
    {
        c[x]++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int res = 0;
    while (x)
    {
        res += c[x];
        x -= lowbit(x);
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        ls[i] = h[i];
    }
    sort(ls + 1, ls + n + 1);
    sz = unique(ls + 1, ls + 1 + n) - ls - 1;
    for (int i = 1; i <= n; i++)
    {
        h[i] = lower_bound(ls + 1, ls + sz + 1, h[i]) - ls;
        edit(h[i]);
        l[i] = i - query(h[i]);
    }
    memset(c, 0, sizeof(c));
    for (int i = n; i >= 1; i--)
    {
        edit(h[i]);
        int r = (n - i + 1) - query(h[i]);
        if (max(r, l[i]) > 2 * min(r, l[i]))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}