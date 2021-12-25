#include <iostream>
using namespace std;
#define MX 1000005
int read();
int n, m, k, cnt, vis[MX];
void dfs(int now)
{
    if (vis[now])
    {
        return;
    }
    cnt--;
    vis[now] = 1;
    int nxt = (now + k) % n;
    dfs(nxt);
}
int main()
{
    cnt = n = read(), m = read(), k = read();
    for (int i = 1; i <= m; i++)
    {
        dfs(read());
    }
    printf("%d\n", cnt);
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