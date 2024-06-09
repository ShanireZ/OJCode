#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
struct Quest
{
    int l, r, k, id, t;
};
Quest qs[100005];
struct Edit
{
    int p, pre, aft;
};
Edit es[100005];
int book[100005], ans[100005], cnt[100005], sz, bpos, cpos, qpos;
map<int, int> mp;
bool cmp(Quest a, Quest b)
{
    if (a.l / sz == b.l / sz)
    {
        if (a.r / sz == b.r / sz)
        {
            return a.t < b.t;
        }
        return a.r < b.r;
    }
    return a.l < b.l;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}
int main()
{
    int n = read(), m = read();
    sz = pow(n, 2.0 / 3.0);
    for (int i = 1; i <= n; i++)
    {
        cin >> book[i];
        if (mp[book[i]] == 0)
        {
            mp[book[i]] = ++bpos;
        }
        book[i] = mp[book[i]];
    }
    for (int i = 1; i <= m; i++)
    {
        char opt;
        cin >> opt;
        if (opt == 'C')
        {
            int a = read(), b = read();
            if (mp[b] == 0)
            {
                mp[b] = ++bpos;
            }
            b = mp[b];
            es[++cpos] = Edit{a, book[a], b};
            book[a] = b;
        }
        else
        {
            int a = read(), b = read(), k = read();
            if (mp[k] == 0)
            {
                mp[k] = ++bpos;
            }
            k = mp[k];
            qs[++qpos] = Quest{a, b, k, qpos, cpos};
        }
    }
    sort(qs + 1, qs + qpos + 1, cmp);
    int now = cpos, st = 1, ed = 0;
    for (int i = 1; i <= qpos; i++)
    {
        while (now < qs[i].t)
        {
            now++;
            if (es[now].p >= st && es[now].p <= ed)
            {
                cnt[es[now].pre]--;
                cnt[es[now].aft]++;
            }
            book[es[now].p] = es[now].aft;
        }
        while (now > qs[i].t)
        {
            if (es[now].p >= st && es[now].p <= ed)
            {
                cnt[es[now].aft]--;
                cnt[es[now].pre]++;
            }
            book[es[now].p] = es[now].pre;
            now--;
        }
        while (ed < qs[i].r)
        {
            ed++;
            cnt[book[ed]]++;
        }
        while (ed > qs[i].r)
        {
            cnt[book[ed]]--;
            ed--;
        }
        while (st < qs[i].l)
        {
            cnt[book[st]]--;
            st++;
        }
        while (st > qs[i].l)
        {
            st--;
            cnt[book[st]]++;
        }
        ans[qs[i].id] = cnt[qs[i].k];
    }
    for (int i = 1; i <= qpos; i++)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}
// TAG: 带修改莫队 离散化 分块