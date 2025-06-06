#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 500005
vector<int> to[MX], scc[MX], pt;
int n, m, npos, spos, dfn[MX], low[MX];
void tarjan(int now)
{
    dfn[now] = low[now] = ++npos;
    pt.push_back(now);
    for (int nxt : to[now])
    {
        if (dfn[nxt] == 0)
        {
            tarjan(nxt);
            low[now] = min(low[now], low[nxt]);
            if (low[nxt] >= dfn[now])
            {
                ++spos;
                while (pt.back() != nxt)
                {
                    scc[spos].push_back(pt.back());
                    pt.pop_back();
                }
                scc[spos].push_back(pt.back()), pt.pop_back();
                scc[spos].push_back(now);
            }
        }
        else
        {
            low[now] = min(low[now], dfn[nxt]);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u != v)
        {
            to[u].push_back(v), to[v].push_back(u);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (dfn[i] == 0)
        {
            if (to[i].size() == 0)
            {
                spos++;
                scc[spos].push_back(i);
            }
            tarjan(i);
        }
    }
    cout << spos << endl;
    for (int i = 1; i <= spos; i++)
    {
        cout << scc[i].size() << " ";
        for (int j : scc[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}