#include <algorithm>
#include <iostream>
using namespace std;
int c[500005], n, m, now, pre;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, int k)
{
    while (x <= n)
    {
        c[x] += k;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += c[x];
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
        int op, x, y, k;
        cin >> op >> x;
        if (op == 1)
        {
            cin >> y >> k;
            edit(x, k), edit(y + 1, -k);
        }
        else
        {
            cout << query(x) << endl;
        }
    }
    return 0;
}