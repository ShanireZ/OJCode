#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
#define MX 20005
struct Node
{
    int x = 10001, y = 10001;
};
Node ns[100005];
long long n, ans, mod = 1e9 + 7, tx[MX], ty[MX], cx[MX], cy[MX], lastx[MX], lasty[MX];
long long read();
bool cmp1(Node a, Node b)
{
    return (a.y == b.y) ? a.x < b.x : a.y < b.y;
}
bool cmp2(Node a, Node b)
{
    return (a.y == b.y) ? a.x > b.x : a.y < b.y;
}
bool cmp3(Node a, Node b)
{
    return (a.y == b.y) ? a.x < b.x : a.y > b.y;
}
bool cmp4(Node a, Node b)
{
    return (a.y == b.y) ? a.x > b.x : a.y > b.y;
}
void solve()
{
    memset(cx, 0, sizeof(cx)), memset(cy, 0, sizeof(cy));
    memset(tx, 0, sizeof(tx)), memset(ty, 0, sizeof(ty));
    memset(lastx, 0, sizeof(lastx)), memset(lasty, 0, sizeof(lasty));
    for (int i = 1; i <= n; i++)
    {
        int x = ns[i].x, y = ns[i].y;
        int prex = lasty[y], prey = lastx[x];
        ty[y] = (ty[y] + cy[y] * abs(x - prex)) % mod;
        tx[x] = (tx[x] + cx[x] * abs(y - prey)) % mod;
        cy[y]++, cx[x]++, lasty[y] = x, lastx[x] = y;
        ans = (ans + tx[x] * ty[y]) % mod;
    }
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        ns[i].x += read(), ns[i].y += read();
    }
    sort(ns + 1, ns + 1 + n, cmp1);
    solve();
    sort(ns + 1, ns + 1 + n, cmp2);
    solve();
    sort(ns + 1, ns + 1 + n, cmp3);
    solve();
    sort(ns + 1, ns + 1 + n, cmp4);
    solve();
    printf("%lld\n", ans);
    return 0;
}
long long read()
{
    int ans = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * f;
}