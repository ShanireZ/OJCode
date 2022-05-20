#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 300005
struct Node_t
{
    int len, fail, ch[26];
};
Node_t ns[MX];
struct Node_s
{
    int lc, rc, v;
};
Node_s seg[MX * 4];
queue<int> q;
string s, mail;
int root_t, root_s, pos, n;
void maketrie()
{
    int now = root_t, sz = s.size();
    for (int i = 0; i < sz; i++)
    {
        int cid = s[i] - 'a';
        if (ns[now].ch[cid] == 0)
        {
            ns[now].ch[cid] = ++pos;
        }
        now = ns[now].ch[cid];
    }
    ns[now].len = sz;
}
int findpos(int now, int cid)
{
    while (now != 0 && ns[now].ch[cid] == 0)
    {
        now = ns[now].fail;
    }
    return (now == 0) ? root_t : ns[now].ch[cid];
}
void makefail()
{
    for (int i = 0; i < 26; i++)
    {
        int now = ns[root_t].ch[i];
        if (now == 0)
        {
            ns[root_t].ch[i] = root_t;
        }
        else
        {
            ns[now].fail = root_t;
            q.push(now);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int nxt = ns[now].ch[i];
            int fail = findpos(ns[now].fail, i);
            if (nxt == 0)
            {
                ns[now].ch[i] = fail;
            }
            else
            {
                ns[nxt].fail = fail;
                ns[nxt].len = max(ns[nxt].len, ns[fail].len);
                q.push(nxt);
            }
        }
    }
}
void makeseg(int &now, int l, int r)
{
    now = ++pos;
    seg[now].v = 0x3f3f3f3f;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    makeseg(seg[now].lc, l, mid);
    makeseg(seg[now].rc, mid + 1, r);
}
void edit(int now, int l, int r, int p, int x)
{
    if (l == r)
    {
        seg[now].v = x;
        return;
    }
    int mid = (l + r) / 2;
    if (p <= mid)
    {
        edit(seg[now].lc, l, mid, p, x);
    }
    else
    {
        edit(seg[now].rc, mid + 1, r, p, x);
    }
    seg[now].v = min(seg[seg[now].lc].v, seg[seg[now].rc].v);
}
int query(int now, int l, int r, int x, int y)
{
    if (x <= l && y >= r)
    {
        return seg[now].v;
    }
    int mid = (l + r) / 2, minv = 0x3f3f3f3f;
    if (x <= mid)
    {
        minv = min(minv, query(seg[now].lc, l, mid, x, y));
    }
    if (y > mid)
    {
        minv = min(minv, query(seg[now].rc, mid + 1, r, x, y));
    }
    return minv;
}
int main()
{
    cin >> n >> mail;
    root_t = pos = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        maketrie();
    }
    makefail();
    pos = 0;
    makeseg(root_s, 1, mail.size());
    int now = root_t, ans;
    for (int i = 0; i < mail.size(); i++)
    {
        now = ns[now].ch[mail[i] - 'a'];
        int len = ns[now].len;
        if (len == 0)
        {
            ans = 0x3f3f3f3f;
            continue;
        }
        if (i - len < 0)
        {
            ans = 0;
            edit(root_s, 1, mail.size(), i + 1, ans + 1);
            continue;
        }
        ans = query(root_s, 1, mail.size(), i - len + 1, i);
        if (ans != 0x3f3f3f3f)
        {
            edit(root_s, 1, mail.size(), i + 1, ans + 1);
        }
    }
    if (ans == 0x3f3f3f3f)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans + 1 << endl;
    }
    return 0;
}