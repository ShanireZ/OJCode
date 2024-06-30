#include <algorithm>
#include <iostream>
using namespace std;
long long ct[2000005], cn[2000005], t[1000005], n, q, a;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, long long ext, long long exn)
{
    while (x <= 2000000 && x > 0)
    {
        ct[x] += ext, cn[x] += exn;
        x += lowbit(x);
    }
}
pair<long long, long long> query(int x)
{
    pair<long long, long long> res = make_pair(0ll, 0ll);
    while (x <= 2000000 && x > 0)
    {
        res.first += ct[x], res.second += cn[x];
        x -= lowbit(x);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        t[a]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (t[i] != 0)
        {
            edit(t[i], t[i], 1); // ct统计出现t[i]次的数字的次数和 cb统计出现t[i]次的数字的个数
        }
    }
    while (q--)
    {
        int op, x;
        cin >> op >> x;
        if (op == 1)
        {
            edit(t[x], -t[x], -1);
            t[x]++;
            edit(t[x], t[x], 1);
        }
        else if (op == 2)
        {
            edit(t[x], -t[x], -1);
            t[x]--;
            edit(t[x], t[x], 1);
        }
        else
        {
            pair<long long, long long> r1 = query(2000000), r2 = query(x);
            cout << r1.first - r2.first - x * (r1.second - r2.second) << '\n';
        }
    }
    return 0;
}