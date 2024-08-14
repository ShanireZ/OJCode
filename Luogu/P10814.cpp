#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 2000005
vector<int> p[MX];
int n, m, a[MX], xq[MX], ans[MX], ts[MX];
void edit(int x)
{
    while (x <= n)
    {
        ts[x]++;
        x += (x & -x);
    }
}
int query(int x)
{
    int res = 0;
    while (x)
    {
        res += ts[x];
        x -= (x & -x);
    }
    return res;
}
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r >> xq[i];
        p[l - 1].emplace_back(i), p[r].emplace_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        edit(a[i]);
        for (int id : p[i])
        {
            ans[id] = query(xq[id]) - ans[id];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}