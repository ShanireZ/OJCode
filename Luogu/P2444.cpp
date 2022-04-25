#include <iostream>
#include <queue>
#include <string>
using namespace std;
#define MX 30005
struct Node
{
    int fail, ch[2], ed;
};
Node ns[MX];
string s;
queue<int> q;
int n, root, pos, ok, vis[MX], his[MX];
void maketrie()
{
    int now = root;
    for (int i = 0; i < s.size(); i++)
    {
        int cid = s[i] - '0';
        if (ns[now].ch[cid] == 0)
        {
            ns[now].ch[cid] = ++pos;
        }
        now = ns[now].ch[cid];
    }
    ns[now].ed = 1;
}
int findpos(int now, int cid)
{
    while (now != 0 && ns[now].ch[cid] == 0)
    {
        now = ns[now].fail;
    }
    return (now == 0) ? root : ns[now].ch[cid];
}
void makefail()
{
    for (int i = 0; i < 2; i++)
    {
        int now = ns[root].ch[i];
        if (now == 0)
        {
            ns[root].ch[i] = root;
        }
        else
        {
            ns[now].fail = root;
            q.push(now);
        }
    }
    while (q.size())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < 2; i++)
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
                ns[nxt].ed = max(ns[nxt].ed, ns[fail].ed);
                q.push(nxt);
            }
        }
    }
}
void dfs(int now)
{
    if (vis[now])
    {
        ok = 1;
        return;
    }
    vis[now] = 1;
    for (int i = 0; i < 2; i++)
    {
        int nxt = ns[now].ch[i];
        if (ns[nxt].ed || his[nxt])
        {
            continue;
        }
        dfs(nxt);
        if (ok)
        {
            return;
        }
    }
    vis[now] = 0, his[now] = 1;
}
int main()
{
    cin >> n;
    root = ++pos;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        maketrie();
    }
    makefail();
    dfs(root);
    if (ok)
    {
        cout << "TAK" << endl;
    }
    else
    {
        cout << "NIE" << endl;
    }
    return 0;
}