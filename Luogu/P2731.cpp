#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
multiset<int> to[505], all, st;
stack<int> s;
int dg[505];
void dfs(int now)
{
    while ((int)to[now].size())
    {
        int nxt = *to[now].begin();
        to[now].erase(to[now].begin());
        to[nxt].erase(to[nxt].find(now));
        dfs(nxt);
    }
    s.push(now);
}
int main()
{
    int m;
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        dg[u]++, dg[v]++;
        to[u].insert(v), to[v].insert(u);
        all.insert(u), all.insert(v);
    }
    for (int i = 1; i <= 500; i++)
    {
        if (dg[i] % 2 == 1)
        {
            st.insert(i);
        }
    }
    int pos = (st.size() == 0 ? *all.begin() : *st.begin());
    dfs(pos);
    while ((int)s.size())
    {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
// TAG: 欧拉路径 欧拉回路 无向图 图的遍历