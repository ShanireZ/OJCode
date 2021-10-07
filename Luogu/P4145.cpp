#include <iostream>
#include <cmath>
using namespace std;
long long read();
long long tree[100005], v[100005], n;
int lowbit(int x)
{
    return x & -x;
}
void edit(int x, long long k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}
long long query(int x)
{
    long long ans = 0;
    while (x)
    {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}
int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
    {
        v[i] = read();
        edit(i, v[i]);
    }
    int m = read();
    for (int i = 1; i <= m; i++)
    {
        int op = read(), l = read(), r = read();
        if (l > r)
        {
            swap(l, r);
        }
        long long sum = query(r) - query(l - 1);
        if (op == 0)
        {
            if (sum == r - l + 1)
            {
                continue;
            }
            for (int j = l; j <= r; j++)
            {
                if (v[j] == 1)
                {
                    continue;
                }
                long long x = sqrt(v[j]);
                edit(j, x - v[j]);
                v[j] = x;
            }
        }
        else
        {
            printf("%lld\n", sum);
        }
    }
    return 0;
}
long long read()
{
    long long ans = 0, type = 1;
    char ch = getchar();
    while (ch != '-' && (ch > '9' || ch < '0'))
    {
        ch = getchar();
    }
    if (ch == '-')
    {
        type = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        ans = ans * 10 + ch - '0';
        ch = getchar();
    }
    return ans * type;
}