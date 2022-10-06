#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MX 200005
int g[MX], sz[MX];  // g[]并查集表示所在子树的根,随着处理会出现变化 sz[]当前子树剩余节点数量
vector<int> to[MX]; // 当前节点能到达的编号更小的点
int dfn(int now)
{
    return (now == g[now]) ? now : g[now] = dfn(g[now]);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            g[i] = i, sz[i] = 1, to[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            (x > y) ? to[x].push_back(y) : to[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) // 从小到大扩展整个树 判断当前节点是否可以成为abc中的c
        {
            int cnt = 0; // 以i为根的子树枝的数量
            for (int j : to[i])
            {
                int gj = dfn(j);
                cnt += bool(sz[gj]), sz[i] += sz[gj];
                g[gj] = i;
            }
            if (cnt >= 2)
            {
                ans++, sz[i] -= 3;
            }
        }
        cout << ans << endl;
    }
    return 0;
}