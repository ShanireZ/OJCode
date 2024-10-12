#include <algorithm>
#include <iostream>
using namespace std;
int g[200005], sz[200005], sum[200005], n, m;
int dfn(int x)
{
    return x == g[x] ? x : g[x] = dfn(g[x]);
}
int main()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            g[i] = g[n + i] = n + i;       // 建立虚拟节点,充当每个组的根节点
            sz[n + i] = 1, sum[n + i] = i; // 移动时只移动不动根节点,分组不会乱
        }
        for (int i = 1; i <= m; i++)
        {
            int opt, x, y;
            cin >> opt >> x;
            if (opt < 3)
            {
                cin >> y;
                int gx = dfn(x), gy = dfn(y);
                if (opt == 1 && gx != gy)
                {
                    g[gx] = gy, sz[gy] += sz[gx], sum[gy] += sum[gx];
                }
                else if (opt == 2 && gx != gy)
                {
                    g[x] = gy, sz[gx]--, sz[gy]++, sum[gx] -= x, sum[gy] += x;
                }
            }
            else
            {
                int gx = dfn(x);
                cout << sz[gx] << " " << sum[gx] << endl;
            }
        }
    }
    return 0;
}