#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
#define MX 1000005
int a[MX], pre0[MX], suf1[MX], st[MX][25], read();
int main()
{
    int n = read(), m = read();
    for (int i = 1; i <= n; i++)
    {
        a[i] = read();
        pre0[i] = pre0[i - 1] + (a[i] == 0), suf1[i] = a[i];
        st[i][0] = i;
    }
    for (int i = n; i >= 1; i--)
    {
        suf1[i] += suf1[i + 1];
    }
    for (int j = 1; j <= 19; j++)
    {
        int len = (1 << (j - 1));
        for (int i = 1; i + len * 2 <= n + 1; i++)
        {
            int p1 = st[i][j - 1], p2 = st[i + len][j - 1];
            st[i][j] = ((pre0[p1] + suf1[p1] < pre0[p2] + suf1[p2]) ? p2 : p1);
        }
    }
    while (m--)
    {
        int opt = read(), l = read(), r = read();
        if (opt == 1)
        {
            int ex = log2(r - l + 1);
            int len = (1 << ex);
            int p1 = st[l][ex], p2 = st[r - len + 1][ex];
            int p = ((pre0[p1] + suf1[p1] < pre0[p2] + suf1[p2]) ? p2 : p1);
            printf("%d\n", pre0[p] + suf1[p] - pre0[l - 1] - suf1[r + 1]);
        }
        else
        {
            int cnt1 = suf1[l] - suf1[r + 1];
            if (suf1[l] - suf1[l + cnt1] == cnt1)
            {
                printf("%d\n", 1);
            }
            else
            {
                printf("%d\n", 2);
            }
        }
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
// https://research-1302056465.cos.ap-shanghai.myqcloud.com/research/Python/20230821170621.png
// TAG: ST表 前缀 后缀 RE