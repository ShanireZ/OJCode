#include <algorithm>
#include <iostream>
using namespace std;
long long c[100005], ci[100005], a[100005], n, m;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, long long k)
{
    long long t = x;
    while (x <= n)
    {
        c[x] += k, ci[x] += t * k;
        x += lowbit(x);
    }
}
long long query(int x)
{
    long long t = x, ans = 0;
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
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        edit(i, a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        string op;
        long long x, y;
        cin >> op >> x;
        if (op == "Modify")
        {
            cin >> y;
            edit(x, y - a[x]);
            a[x] = y;
        }
        else
        {
            cout << query(x) << endl;
        }
    }
    return 0;
}