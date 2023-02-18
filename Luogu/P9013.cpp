#include <iostream>
#include <string>
using namespace std;
string a, b;
int vis[100], g[100], to[100], ind[100], ring[100];
int dfn(int x)
{
    if (g[x] != x)
    {
        g[x] = dfn(g[x]);
    }
    return g[x];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ans = 0, cnt = 0, pos = 0;
        for (int i = 0; i < 100; i++)
        {
            g[i] = i, to[i] = -1, vis[i] = ind[i] = 0;
        }
        cin >> a >> b;
        for (int i = 0; i < int(a.size()); i++)
        {
            int u = a[i] - 'A', v = b[i] - 'A';
            if (to[u] == -1)
            {
                to[u] = v, ans += (u != v), ind[v]++;
                cnt += (vis[v] == 0), vis[v] = 1;
            }
            else if (to[u] != v) // 出现冲突 一个字符无法变为多个不同字符
            {
                ans = -1;
                break;
            }
        }
        if (ans == -1 || (cnt == 52 && a != b)) // 如果没有可供中转的位置也无法转换
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 0; i < 100; i++) //  每个独立环需要额外中转一次
        {
            if (to[i] != i && to[i] == -1)
            {
                int gu = dfn(i), gv = dfn(to[i]);
                (gu != gv) ? (g[gu] = gv) : (ring[++pos] = gv);
            }
        }
        for (int i = 1; i <= pos; i++)
        {
            int gid = dfn(ring[i]), ok = 1;
            for (int j = 0; j < 100; j++)
            {
                if (gid == dfn(j) && ind[j] > 1)
                {
                    ok = 0;
                    break;
                }
            }
            ans += ok;
        }
        cout << ans << "\n";
    }
    return 0;
}