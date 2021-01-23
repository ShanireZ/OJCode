#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 5e4 + 5;
long long a[maxn], p[maxn], ans[maxn][2], ts[maxn];
struct Quest
{
    int l, r, id;
};
Quest quest[maxn];
bool cmp(Quest a, Quest b)
{
    if (p[a.l] == p[b.l])
    {
        return a.r < b.r;
    }
    return a.l < b.l;
}
long long cx2(long long x)
{
    return x * (x - 1) / 2;
}
long long gcd(long long a, long long b)
{
    int r;
    while (b)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void add(int x, int id)
{
    int num = a[x];
    ans[id][0] -= cx2(ts[num]);
    ts[num]++;
    ans[id][0] += cx2(ts[num]);
}
void sub(int x, int id)
{
    int num = a[x];
    ans[id][0] -= cx2(ts[num]);
    ts[num]--;
    ans[id][0] += cx2(ts[num]);
}
int main()
{
    int n, m;
    cin >> n >> m;
    int block = sqrt(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i] = i / block;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> quest[i].l >> quest[i].r;
        quest[i].id = i;
    }
    sort(quest + 1, quest + 1 + m, cmp);
    int st = 1, ed = 0;
    for (int i = 1; i <= m; i++)
    {
        int id = quest[i].id;
        int pre = quest[i - 1].id;
        ans[id][0] = ans[pre][0];
        ans[id][1] = cx2(quest[i].r - quest[i].l + 1);
        while (st > quest[i].l)
        {
            add(--st, id);
        }
        while (st < quest[i].l)
        {
            sub(st++, id);
        }
        while (ed < quest[i].r)
        {
            add(++ed, id);
        }
        while (ed > quest[i].r)
        {
            sub(ed--, id);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i][0] == 0 || ans[i][1] == 0)
        {
            cout << "0/1" << endl;
            continue;
        }
        int x = gcd(ans[i][0], ans[i][1]);
        cout << ans[i][0] / x << "/" << ans[i][1] / x << endl;
    }
    return 0;
}