#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> all;
int n, m, h[300005], v[300005], c[300005];
int lowbit(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= n)
    {
        v[x]++, x += lowbit(x);
    }
}
int query(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += v[x], x -= lowbit(x);
    }
    return res;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
        all.push_back(h[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 1; i <= n; i++)
    {
        h[i] = lower_bound(all.begin(), all.end(), h[i]) - all.begin() + 1;
    }
    long long ans = 0;
    for (int i = n; i > 0; i--)
    {
        int x = query(h[i] - 1);
        c[h[i]] += x, ans += x, edit(h[i]);
    }
    cout << ans << endl;
    int now = 0;
    for (int i = 1; i <= m; i++)
    {
        int k;
        cin >> k;
        while (now < h[k])
        {
            now++;
            ans -= c[now];
        }
        cout << ans << endl;
    }
    return 0;
}
// TAG: 树状数组 线段树 逆序对