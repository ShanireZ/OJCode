#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, now, pre, c[100005], ci[100005];
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, long long k)
{
    int t = x;
    while (x <= n)
    {
        c[x] += k;
        x += lowbit(x);
    }
    x = t;
    while (x <= n)
    {
        ci[x] += k * t;
        x += lowbit(x);
    }
}
long long query(int x)
{
    long long ans = 0, t = x;
    while (x)
    {
        ans += (t + 1) * c[x] - ci[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++, pre = now)
    {
        cin >> now;
        edit(i, now - pre);
    }
    for (int i = 1; i <= m; i++)
    {
        long long op, x, y, k;
        cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            edit(x, k), edit(y + 1, -k);
        }
        else
        {
            cout << query(y) - query(x - 1) << endl;
        }
    }
    return 0;
}