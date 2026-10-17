#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define MX 200005
int g[MX], sz[MX];  // g[]並查集表示所在子樹的根,隨著處理會出現變化 sz[]當前子樹剩餘節點數量
vector<int> to[MX]; // 當前節點能到達的編號更小的點
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
        for (int i = 1; i <= n; i++) // 從小到大擴充整個樹 判斷當前節點是否可以成為abc中的c
        {
            int cnt = 0; // 以i為根的子樹枝的數量
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