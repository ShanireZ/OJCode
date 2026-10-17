#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define MX 200005
long long read();
long long st[MX], ed[MX], add[MX * 2], red[MX * 2];
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        int a = read(), b = read();
        st[a]++, ed[b]++;
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            add[i + j] += st[i] * st[j];     // k=i+j時 以i j開始的這些新增了許多情況
            red[i + j + 1] += ed[i] * ed[j]; // k=i+j+1時 以i j結束的這些就不符合k<=bi+bj了
        }
    }
    printf("%lld\n", add[0]);
    for (int i = 1; i <= m * 2; i++) // 能滿足x 肯定就能滿足x+1 求前綴和
    {
        add[i] += add[i - 1];
        red[i] += red[i - 1];
        printf("%lld\n", add[i] - red[i]);
    }
    return 0;
}
long long read()
{
    long long ans = 0;
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