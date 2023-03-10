#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define MX 1000005
int read(), lson[MX], dp[MX], maxdp[MX], hd[MX], fa[MX], ans[MX];
vector<int> chs[MX], cnt[MX]; // cnt[i][j] 以i为根的子树中,距离maxdp[i]为j的点的个数
void init(int now, int deep)
{
    dp[now] = maxdp[now] = deep;
    for (int nxt : chs[now])
    {
        if (nxt == fa[now])
        {
            continue;
        }
        fa[nxt] = now, init(nxt, deep + 1);
        if (maxdp[nxt] > maxdp[now])
        {
            maxdp[now] = maxdp[nxt], lson[now] = nxt;
        }
    }
}
void dfs(int now, int top)
{
    hd[now] = top;
    if (lson[now])
    {
        dfs(lson[now], top);
        swap(cnt[now], cnt[lson[now]]);
        ans[now] = ans[lson[now]];
        for (int nxt : chs[now])
        {
            if (nxt == fa[now] || nxt == lson[now])
            {
                continue;
            }
            dfs(nxt, nxt);
            int pos = maxdp[now] - maxdp[nxt];
            for (int i = 0; i < (int)cnt[nxt].size(); i++)
            {
                cnt[now][pos + i] += cnt[nxt][i];
                if ((cnt[now][pos + i] > cnt[now][ans[now]]) ||
                    (cnt[now][pos + i] == cnt[now][ans[now]] && pos + i > ans[now]))
                {
                    ans[now] = pos + i;
                }
            }
        }
        if (cnt[now][ans[now]] == 1)
        {
            ans[now] = maxdp[now] - dp[now];
        }
    }
    cnt[now].push_back(1);
}
int main()
{
    int n = read(), root = 1;
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        chs[u].push_back(v), chs[v].push_back(u);
    }
    init(root, 1);
    dfs(root, root);
    for (int i = 1; i <= n; i++)
    {
        cout << maxdp[i] - dp[i] - ans[i] << "\n";
    }
    return 0;
}
int read()
{
    int ans = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans;
}