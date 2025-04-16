#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> to[200005];
set<int> st;
int n, m, g[200005], sz[200005];
int dfn(int x)
{
    return g[x] == x ? x : g[x] = dfn(g[x]);
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        to[u].emplace_back(v), to[v].emplace_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        g[i] = i, sz[i] = 1;
    }
    for (int k = 1; k <= n; k++)
    {
        st.erase(k);
        for (int nxt : to[k])
        {
            if (nxt < k)
            {
                int a = dfn(k), b = dfn(nxt);
                if (a != b)
                {
                    g[b] = a, sz[a] += sz[b];
                }
            }
            else
            {
                st.insert(nxt);
            }
        }
        if (sz[dfn(1)] != k)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << st.size() << endl;
        }
    }
    return 0;
}