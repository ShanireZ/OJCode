#include <iostream>
using namespace std;
int N, read();
long long tree[100005], cnt[100005];
int lb(int x)
{
    return x & -x;
}
void edit(int x)
{
    while (x <= N)
    {
        tree[x]++;
        x += lb(x);
    }
}
long long query(int x)
{
    long long ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lb(x);
    }
    return ans;
}
int main()
{
    int n = read();
    N = n + 1;
    for (int i = 1; i <= n; i++)
    {
        int x = read() + 1;
        cnt[x] += query(N) - query(x);
        edit(x);
    }
    long long tot = 0;
    for (int i = 1; i < N; i++)
    {
        printf("%lld\n", tot);
        tot += cnt[i];
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