#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MX 500005
unsigned int s;
int read(), root, anc[MX][20], lson[MX], dp[MX], maxdp[MX], hd[MX];
vector<int> chs[MX], up[MX], down[MX];
void init(int now, int deep)
{
    dp[now] = maxdp[now] = deep;
    for (int i = 1; i <= log2(deep); i++)
    {
        anc[now][i] = anc[anc[now][i - 1]][i - 1];
    }
    for (int nxt : chs[now])
    {
        init(nxt, deep + 1);
        if (maxdp[nxt] > maxdp[now])
        {
            maxdp[now] = maxdp[nxt], lson[now] = nxt;
        }
    }
}
void dfs(int now, int top)
{
    hd[now] = top;
    if (now == top)
    {
        for (int i = 0, x = now; i <= maxdp[now] - dp[now] && x; i++)
        {
            up[now].push_back(x), x = anc[x][0];
        }
        for (int i = 0, x = now; i <= maxdp[now] - dp[now]; i++)
        {
            down[now].push_back(x), x = lson[x];
        }
    }
    if (lson[now])
    {
        dfs(lson[now], top);
        for (int nxt : chs[now])
        {
            if (nxt != lson[now])
            {
                dfs(nxt, nxt);
            }
        }
    }
}
int findanc(int x, int k)
{
    if (k == 0)
    {
        return x;
    }
    int cm = log2(k);
    x = anc[x][cm], k -= (int)pow(2, cm);
    k -= dp[x] - dp[hd[x]], x = hd[x];
    return (k >= 0 ? up[x][k] : down[x][-k]);
}
inline unsigned int get(unsigned int x)
{
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    return s = x;
}
int main()
{
    int n = read(), q = read();
    scanf("%u", &s);
    for (int i = 1; i <= n; i++)
    {
        int x = read();
        anc[i][0] = x, chs[x].push_back(i);
    }
    root = chs[0][0];
    init(root, 1), dfs(root, root);
    long long ans = 0, last = 0;
    for (int i = 1; i <= q; i++)
    {
        int x = (get(s) ^ last) % n + 1;
        int k = (get(s) ^ last) % dp[x];
        last = findanc(x, k);
        ans ^= i * last;
    }
    printf("%lld\n", ans);
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
// TAG: 树链剖分 长链剖分 K级祖先