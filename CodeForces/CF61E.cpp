#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n, a[1000005], pre[1000005], suf[1000005];
vector<int> all;
int lowbit(int x)
{
    return x & -x;
}
void init(int x)
{
    while (x <= n)
    {
        suf[x]++;
        x += lowbit(x);
    }
}
void edit(int x)
{
    while (x <= n)
    {
        pre[x]++, suf[x]--;
        x += lowbit(x);
    }
}
pair<int, int> query(int x)
{
    pair<int, int> res = {0, 0};
    while (x > 0)
    {
        res.first += pre[x], res.second += suf[x];
        x -= lowbit(x);
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end());
    for (int i = 1; i <= n; i++)
    {
        a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
        init(a[i]);
    }
    long long ans = 0;
    edit(a[1]);
    for (int i = 2; i < n; i++)
    {
        edit(a[i]);
        pair<int, int> res = query(a[i]);
        ans += 1ll * (i - res.first) * res.second;
    }
    cout << ans << endl;
    return 0;
}
// TAG: 树状数组 线段树 逆序对 动态维护