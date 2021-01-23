#include <cstdio>
#include <algorithm>
using namespace std;
struct Node
{
    int v, id;
};
int at[100005], sx[100005], mod = 1e8 - 3, n;
Node a[100005], b[100005];
bool cmp(Node a, Node b)
{
    return a.v < b.v;
}
int lowbit(int x)
{
    return x & -x;
}
void edit(int now)
{
    while (now <= n)
    {
        at[now]++;
        now += lowbit(now);
    }
}
int findnow(int now)
{
    int ans = 0;

    while (now)
    {
        ans += at[now];
        now -= lowbit(now);
    }

    return ans;
}
int read()
{ //快读
    char ch = getchar();

    while ((ch > '9' || ch < '0') && ch != '-')
    {
        ch = getchar();
    }

    int t = 1, n = 0;

    if (ch == '-')
    {
        t = -1;
        ch = getchar();
    }

    while (ch >= '0' && ch <= '9')
    {
        n = n * 10 + ch - '0';
        ch = getchar();
    }

    return n * t;
}
int main()
{
    n = read();

    for (int i = 1; i <= n; i++)
    { //初始化a
        a[i].v = read();
        a[i].id = i;
    }

    sort(a + 1, a + 1 + n, cmp); //排序a 离散化准备

    for (int i = 1; i <= n; i++)
    { //初始化b
        b[i].v = read();
        b[i].id = i;
    }

    sort(b + 1, b + 1 + n, cmp); //排序b 离散化准备

    for (int i = 1; i <= n; i++)
    { //离散化 双数组映射
        sx[a[i].id] = b[i].id;
    }

    long long tot = 0;

    for (int i = 1; i <= n; i++)
    {                //统计逆序对 假设第i个数为x 之前出现了几个比x大的数
        edit(sx[i]); //次数喜加一
        tot += findnow(n) - findnow(sx[i]);
        tot %= mod;
    }

    printf("%lld", tot);
    return 0;
}