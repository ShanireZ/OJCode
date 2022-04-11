#include <iostream>
using namespace std;
// 链式前向星全套 存储原无根树
struct Edge
{
    int to, w, pre;
};
Edge es[200005];
int fa[100005], last[100005];
// 原理 x xor y xor y = x
// 点x至点y的亦或路径 = 点x至根节点的亦或路径 xor 点y至根节点的亦或路径
// 设原树根为节点1
// bin存储 每个点到根节点的亦或路径值的二进制形式 其中1为最低位 31为最高位
// trie为bin数组的01trie
int bin[100005][35], trie[3500005][2], n, pos, ans;
void make_trie(int id, int xr) // 记录bin并据此建01trie
{
    int p = 0;
    while (xr)
    {
        bin[id][++p] = xr % 2;
        xr /= 2;
    }
    int now = 0;
    for (int i = 31; i >= 1; i--)
    {
        int v = bin[id][i];
        if (trie[now][v] == 0)
        {
            trie[now][v] = ++pos;
        }
        now = trie[now][v];
    }
}
void dfs(int now, int xr) // 搜搜原树 计算每个点至根节点的亦或路径
{
    make_trie(now, xr);
    for (int i = last[now]; i != 0; i = es[i].pre)
    {
        int to = es[i].to, w = es[i].w;
        if (to == fa[now])
        {
            continue;
        }
        fa[to] = now;
        dfs(to, xr ^ w);
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        es[++pos] = {v, w, last[u]};
        last[u] = pos;
        es[++pos] = {u, w, last[v]};
        last[v] = pos;
    }
    dfs(1, 0);
    // 贪心求解每个点在01trie的最大亦或路径
    // 贪心条件是高位优先找不同的路径
    for (int i = 1; i <= n; i++)
    {
        int xr = 0, now = 0;
        for (int j = 31; j >= 1; j--)
        {
            int x = bin[i][j];
            if (trie[now][1 - x] == 0)
            {
                xr = xr * 2;
                now = trie[now][x];
            }
            else
            {
                xr = xr * 2 + 1;
                now = trie[now][1 - x];
            }
        }
        ans = max(ans, xr);
    }
    cout << ans << endl;
    return 0;
}