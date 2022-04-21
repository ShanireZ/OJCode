#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
#define MX 100005
struct Node
{
    int dfn, last, tfa, fail, tch[26];
    vector<int> sid, fch;
};
Node ns[MX];
struct Quest
{
    int x, qid;
    Quest(int X, int Qid)
    {
        x = X, qid = Qid;
    }
};
vector<Quest> qst[MX];
queue<int> q;
string s;
int m, root, tpos, spos, dpos, ed[MX], ans[MX], t[MX];
int lowbit(int x)
{
    return x & -x;
}
void edit(int now, int ex)
{
    while (now <= dpos)
    {
        t[now] += ex;
        now += lowbit(now);
    }
}
int query(int now)
{
    int ans = 0;
    while (now)
    {
        ans += t[now];
        now -= lowbit(now);
    }
    return ans;
}
void maketrie()
{
    int now = root = ++tpos;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P')
        {
            ed[++spos] = now;
            ns[now].sid.push_back(spos);
        }
        else if (s[i] == 'B')
        {
            now = ns[now].tfa;
        }
        else
        {
            int cid = s[i] - 'a';
            if (ns[now].tch[cid] == 0)
            {
                ns[now].tch[cid] = ++tpos;
                ns[tpos].tfa = now;
            }
            now = ns[now].tch[cid];
        }
    }
}
int findpos(int now, int cid)
{
    while (now != 0 && ns[now].tch[cid] == 0)
    {
        now = ns[now].fail;
    }
    return (now == 0) ? root : ns[now].tch[cid];
}
void makefail()
{
    for (int i = 0; i < 26; i++)
    {
        int now = ns[root].tch[i];
        if (now)
        {
            q.push(now);
            ns[now].fail = root;
            ns[root].fch.push_back(now);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
        {
            int nxt = ns[now].tch[i];
            int fail = findpos(ns[now].fail, i);
            if (nxt == 0)
            {
                ns[now].tch[i] = fail;
            }
            else
            {
                ns[nxt].fail = fail;
                ns[fail].fch.push_back(nxt);
                q.push(nxt);
            }
        }
    }
}
void dfs(int now)
{
    ns[now].dfn = ++dpos;
    for (int i = 0; i < ns[now].fch.size(); i++)
    {
        int nxt = ns[now].fch[i];
        dfs(nxt);
    }
    ns[now].last = dpos;
}
void solve()
{
    int now = root;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'P')
        {
            for (int j = 0; j < ns[now].sid.size(); j++)
            {
                int y = ns[now].sid[j];
                if (qst[y].size() == 0)
                {
                    continue;
                }
                for (int k = 0; k < qst[y].size(); k++)
                {
                    int x = qst[y][k].x, qid = qst[y][k].qid;
                    ans[qid] = query(ns[ed[x]].last) - query(ns[ed[x]].dfn - 1);
                }
            }
        }
        else if (s[i] == 'B')
        {
            edit(ns[now].dfn, -1);
            now = ns[now].tfa;
        }
        else
        {
            int cid = s[i] - 'a';
            now = ns[now].tch[cid];
            edit(ns[now].dfn, 1);
        }
    }
}
int main()
{
    cin >> s >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        qst[y].push_back(Quest(x, i));
    }
    maketrie();
    makefail();
    dfs(root);
    solve();
    for (int i = 1; i <= m; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}