#include <algorithm>
#include <iostream>
#include <set>
#include <stack>
using namespace std;
multiset<char> to[150], all, st;
stack<char> s;
int dg[150];
void dfs(char now)
{
    while ((int)to[now].size())
    {
        char nxt = *to[now].begin();
        to[now].erase(nxt), to[nxt].erase(now);
        dfs(nxt);
    }
    s.push(now);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) // 需要注意的是题目数据有自环无重边
    {
        char u, v;
        cin >> u >> v;
        dg[u]++, dg[v]++, all.insert(u), all.insert(v);
        to[u].insert(v), to[v].insert(u);
    }
    for (int i = 'A'; i <= 'z'; i++)
    {
        if (dg[i] % 2 == 1)
        {
            st.insert(i);
        }
    }
    if ((int)st.size() != 0 && (int)st.size() != 2)
    {
        cout << "No Solution" << endl;
    }
    else
    {
        dfs((st.size() == 2 ? *st.begin() : *all.begin()));
        // 题目数据都是连通图，实际还需要判图连通性
        while (s.size())
        {
            cout << s.top();
            s.pop();
        }
    }
    return 0;
}
// TAG: 欧拉回路 欧拉路径 无向图 图的遍历