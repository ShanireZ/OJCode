#include <algorithm>
#include <iostream>
using namespace std;
struct Node
{
    int op, x, y;
};
Node ns[200005];
int a[200005], c[200005], n, m, k;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, int k)
{
    while (x <= m)
    {
        c[x] = (c[x] + k + 10007) % 10007;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans = (c[x] + ans + 10007) % 10007;
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int id;
        cin >> id;
        edit(id, 1), edit(id + 1, -1);
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> ns[i].op >> ns[i].x >> ns[i].y;
    }
    for (int i = m; i >= 1; i--)
    {
        int t = query(i);
        if (ns[i].op == 2)
        {
            edit(ns[i].x, t), edit(ns[i].y + 1, -t);
        }
        else if (ns[i].op == 1)
        {
            a[ns[i].x] = (a[ns[i].x] + ns[i].y * t % 10007) % 10007;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}