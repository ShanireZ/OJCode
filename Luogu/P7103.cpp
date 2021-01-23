#include <cstdio>
using namespace std;
int read();
struct Child
{
    int id, pre;
};
Child chl[5000005]; //链式前向*存树 vector会被卡
int tree[5000005], g[5000005], ans[5000005];
int uf(int x)
{
    if (x != g[x])
    {
        g[x] = uf(g[x]);
    }
    return g[x];
}
void tarjan(int x, int dp)
{
    g[x] = x;
    for (int i = tree[x]; chl[i].id; i = chl[i].pre)
    {
        int id = chl[i].id;
        tarjan(id, dp + 1);
        int gx = uf(x), gy = uf(id);
        g[gy] = gx;
    }
    if (ans[dp] == 0)
    {
        ans[dp] = x;
    }
    else
    {
        ans[dp] = uf(ans[dp]);
    }
}
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        int fa = read();
        chl[i].id = i;
        chl[i].pre = tree[fa];
        tree[fa] = i;
    }
    tarjan(1, 1); //root固定为1 root深度为1
    for (int i = 1; i <= m; i++)
    {
        int dp = read();
        printf("%d\n", ans[dp]);
    }
    return 0;
}
int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = (x * 10) + (ch - '0');
        ch = getchar();
    }
    return x;
}