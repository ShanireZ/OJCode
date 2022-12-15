#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int cnt[105], deep[105], fa[105], read();
vector<int> chs[105];
queue<int> q;
int main() // 统计树上每层叶节点数量
{
    int n = read(), m = read();
    for (int i = 1; i <= m; i++)
    {
        int u = read(), k = read();
        for (int j = 1; j <= k; j++)
        {
            int v = read();
            fa[v] = u, chs[u].push_back(v);
        }
    }
    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        if (fa[i] == 0)
        {
            root = i;
            break;
        }
    }
    deep[root] = 1, q.push(root);
    int maxdp = 1;
    while (q.size())
    {
        int now = q.front();
        q.pop();
        if (chs[now].size() == 0)
        {
            cnt[deep[now]]++;
        }
        for (int i = 0; i < int(chs[now].size()); i++)
        {
            int nxt = chs[now][i];
            deep[nxt] = deep[now] + 1, q.push(nxt);
            maxdp = max(maxdp, deep[nxt]);
        }
    }
    printf("%d", cnt[1]);
    for (int i = 2; i <= maxdp; i++)
    {
        printf(" %d", cnt[i]);
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