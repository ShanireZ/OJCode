#include <cstdio>
#include <ctime>
#include <random>
using namespace std;
#define MX 500005
mt19937 rseed(time(0));
uniform_int_distribution<int> rnd(1, 1000000000);
int n, m, q;
long long ans1, ans2, now1, now2, w1[MX], w2[MX], tot1[MX], tot2[MX], st1[MX], st2[MX];
// ans:所有点的和 now:所有现存边起点和 w:每个点的值
// st:每个点所有入边的起点和 tot:每个点现存入边的起点和
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
int main() // 如果所有点出度为1即可反攻=每个起点在边中只出现1次=(所有现存边起点和==所有点的和)
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        w1[i] = rseed(), ans1 += w1[i];
        w2[i] = rseed(), ans2 += w2[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read();
        now1 += w1[u], now2 += w2[u];
        st1[v] += w1[u], tot1[v] += w1[u];
        st2[v] += w2[u], tot2[v] += w2[u];
    }
    q = read();
    while (q--)
    {
        int opt = read();
        if (opt == 1)
        {
            int u = read(), v = read();
            tot1[v] -= w1[u], now1 -= w1[u];
            tot2[v] -= w2[u], now2 -= w2[u];
        }
        else if (opt == 2)
        {
            int u = read();
            now1 -= tot1[u], tot1[u] = 0;
            now2 -= tot2[u], tot2[u] = 0;
        }
        else if (opt == 3)
        {
            int u = read(), v = read();
            tot1[v] += w1[u], now1 += w1[u];
            tot2[v] += w2[u], now2 += w2[u];
        }
        else
        {
            int u = read();
            now1 += st1[u] - tot1[u], tot1[u] = st1[u];
            now2 += st2[u] - tot2[u], tot2[u] = st2[u];
        }
        if (ans1 == now1 && ans2 == now2)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}