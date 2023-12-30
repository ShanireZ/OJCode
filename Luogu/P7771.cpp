#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
stack<int> s;
multiset<int> to[100005];
int ind[100005], otd[100005], st = 0, ed = 0;
void dfs(int now)
{
    while (to[now].size())
    {
        int nxt = *to[now].begin();
        to[now].erase(to[now].begin());
        dfs(nxt);
    }
    s.push(now);
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].insert(v), ind[v]++, otd[u]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (otd[i] - ind[i] == 1 && st == 0)
        {
            st = i;
        }
        else if (ind[i] - otd[i] == 1 && ed == 0)
        {
            ed = i;
        }
        else if (ind[i] != otd[i])
        {
            st = ed = -1;
        }
    }
    if ((st > 0 && ed > 0) || (st == 0 && ed == 0))
    {
        int now = (st == 0 ? 1 : st);
        dfs(now);
        while (s.size())
        {
            cout << s.top() << " ";
            s.pop();
        }
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
// TAG: 欧拉路径 欧拉回路 图的遍历