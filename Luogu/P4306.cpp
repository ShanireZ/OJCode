#include <bitset>
#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 2005
struct Node
{
    int dfn, low, g;
};
Node ns[MX];
struct Scc
{
    int sz, ind;
    bitset<MX> via;
};
Scc scc[MX];
int to[MX * MX * 2], pre[MX * MX * 2], slast[MX], last[MX], s[MX];
int n, spos, gpos, epos, npos, ans;
queue<int> q;
void tarjan(int now)
{
    ns[now].dfn = ns[now].low = ++npos, s[++spos] = now;
    for (int i = last[now]; i != 0; i = pre[i])
    {
        int nxt = to[i];
        if (ns[nxt].dfn == 0)
        {
            tarjan(nxt);
            ns[now].low = min(ns[now].low, ns[nxt].low);
        }
        else if (ns[nxt].g == 0)
        {
            ns[now].low = min(ns[now].low, ns[nxt].dfn);
        }
    }
    if (ns[now].low == ns[now].dfn)
    {
        gpos++;
        while (s[spos] != now)
        {
            ns[s[spos--]].g = gpos, scc[gpos].sz++;
        }
        ns[s[spos--]].g = gpos, scc[gpos].sz++;
    }
}
void Sp()
{
    for (int i = 1; i <= gpos; i++)
    {
        scc[i].via[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int gi = ns[i].g;
        for (int j = last[i]; j != 0; j = pre[j])
        {
            int gt = ns[to[j]].g;
            if (gi == gt)
            {
                continue;
            }
            scc[gi].via[gt] = 1;
            scc[gi].ind++; // 反向图 gt->gi
            to[++epos] = gi;
            pre[epos] = slast[gt];
            slast[gt] = epos;
        }
    }
}
void Tp()
{
    for (int i = 1; i <= gpos; i++)
    {
        if (scc[i].ind == 0)
        {
            q.push(i);
        }
    }
    while (q.size())
    {
        int f = q.front();
        q.pop();
        for (int i = slast[f]; i != 0; i = pre[i])
        {
            int t = to[i];
            scc[t].ind--;
            if (scc[t].ind == 0)
            {
                q.push(t);
            }
            scc[t].via |= scc[f].via;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        int p = s.find('1');
        while (p != string::npos) // i->p+1
        {
            to[++epos] = p + 1;
            pre[epos] = last[i];
            last[i] = epos;
            p = s.find('1', p + 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    Sp();
    Tp();
    for (int i = 1; i <= gpos; i++)
    {
        for (int j = 1; j <= gpos; j++)
        {
            ans += scc[i].sz * scc[j].sz * scc[i].via[j];
        }
    }
    cout << ans << endl;
    return 0;
}