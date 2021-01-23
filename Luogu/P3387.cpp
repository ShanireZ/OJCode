#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
struct Node
{
    int in, dfn, low, g, p;
    vector<int> way;
};
Node ns[10005];
struct NodeN
{
    int ind, p, dp;
    vector<int> way;
};
NodeN nsn[10005];
stack<int> stk;
queue<int> q;
int pos, gid, maxn;
void tarjan(int x)
{
    ns[x].low = ns[x].dfn = ++pos;
    ns[x].in = 1;
    stk.push(x);
    for (int i = 0; i < ns[x].way.size(); i++)
    {
        int id = ns[x].way[i];
        if (ns[id].dfn == 0)
        {
            tarjan(id);
            ns[x].low = min(ns[x].low, ns[id].low);
        }
        else if (ns[id].in)
        {
            ns[x].low = min(ns[x].low, ns[id].dfn);
        }
    }
    if (ns[x].dfn == ns[x].low)
    {
        int id;
        gid++;
        do
        {
            id = stk.top();
            stk.pop();
            ns[id].in = 0;
            ns[id].g = gid;
        } while (id != x);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].p;
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        ns[a].way.push_back(b);
    }
    for (int i = 1; i <= n; i++) //找出强连通
    {
        if (ns[i].dfn == 0)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) //缩点
    {
        int id = ns[i].g;
        nsn[id].p += ns[i].p;
        nsn[id].dp += ns[i].p;
        for (int j = 0; j < ns[i].way.size(); j++)
        {
            int nid = ns[ns[i].way[j]].g;
            if (nid != id)
            {
                nsn[id].way.push_back(nid);
            }
        }
    }
    for (int i = 1; i <= gid; i++) //更新缩点链接情况
    {
        sort(nsn[i].way.begin(), nsn[i].way.end());
        nsn[i].way.erase(unique(nsn[i].way.begin(), nsn[i].way.end()), nsn[i].way.end());
        for (int j = 0; j < nsn[i].way.size(); j++)
        {
            int id = nsn[i].way[j];
            nsn[id].ind++;
        }
    }
    for (int i = 1; i <= gid; i++)
    {
        if (nsn[i].ind == 0)
        {
            q.push(i);
        }
    }
    while (q.size()) //拓扑序遍历DP
    {
        int id = q.front();
        q.pop(); //! 拓扑序
        for (int i = 0; i < nsn[id].way.size(); i++)
        {
            int nid = nsn[id].way[i];
            nsn[nid].ind--;
            nsn[nid].dp = max(nsn[nid].dp, nsn[id].dp + nsn[nid].p);
            if (nsn[nid].ind == 0)
            {
                q.push(nid);
            }
        }
    }
    for (int i = 1; i <= gid; i++)
    {
        maxn = max(maxn, nsn[i].dp);
    }
    cout << maxn;
    return 0;
}