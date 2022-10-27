#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
#define MX 500005
struct Missile
{
    double st, ed, v;
    int y, sr, id;
};
Missile ms[MX];
int n, m, tree[MX], p[MX], del[MX];
map<int, pair<int, int>> mp;
bool cmpst(Missile a, Missile b)
{
    if (a.y == b.y)
    {
        return a.st < b.st;
    }
    return a.y < b.y;
}
bool cmped(Missile a, Missile b)
{
    if (a.y == b.y)
    {
        return a.ed < b.ed;
    }
    return a.y < b.y;
}
int lowbit(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= n)
    {
        tree[x]++;
        x += lowbit(x);
    }
}
int query(int x)
{
    int ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ms[i].id = i;
        cin >> ms[i].st >> ms[i].y >> ms[i].v;
        ms[i].ed = ms[i].st + ms[i].v * sqrt(2.0 * ms[i].y / 9.8);
    }
    ms[0].y = -1;
    sort(ms + 1, ms + 1 + n, cmpst);
    for (int i = 1; i <= n; i++)
    {
        if (ms[i].y != ms[i - 1].y)
        {
            mp[ms[i].y].first = i;
        }
        ms[i].sr = mp[ms[i].y].second = i;
    }
    sort(ms + 1, ms + 1 + n, cmped);
    for (int i = 1; i <= n; i++) // 比i早结束且开始比i晚-->i包含的
    {
        p[ms[i].id] += query(mp[ms[i].y].second) - query(ms[i].sr);
        edit(ms[i].sr);
    }
    memset(tree, 0, sizeof(tree));
    for (int i = n; i >= 1; i--) // 比i晚结束且开始比i早-->所含i的
    {
        p[ms[i].id] += query(ms[i].sr) - query(mp[ms[i].y].first - 1);
        edit(ms[i].sr);
    }
    long long tot = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> del[i];
        del[i] = min(del[i], p[i]), tot += p[i];
    }
    sort(del + 1, del + 1 + n);
    for (int i = n; i >= n - m + 1; i--)
    {
        tot -= del[i];
    }
    cout << tot << endl;
    return 0;
}