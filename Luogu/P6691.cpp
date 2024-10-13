#include <iostream>
using namespace std;
#define MX 1000005
int g[MX], r[MX], c1[MX], c0[MX], mod = 998244353, n;
// r[i]:i与上级间是否同调 1:同调 0:不同调
int dfn(int x)
{
    if (x != g[x])
    {
        int fx = g[x];          // 保存原上层节点编号
        g[x] = dfn(g[x]);       // 路径压缩返回后,上层的同调性已更新
        r[x] = (r[x] == r[fx]); // 更新自己的同调性
    }
    return g[x];
}
long long qmod(int k)
{
    long long res = 1, base = 2;
    while (k)
    {
        if (k % 2 == 1)
        {
            res = res * base % mod;
        }
        base = base * base % mod, k /= 2;
    }
    return res;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        g[i] = i, r[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int a, opt;
        cin >> a >> opt; // opt=1:同调 opt=0:不同调
        int fi = dfn(i), fa = dfn(a);
        if (fi == fa)
        {
            if ((r[i] == r[a]) != opt)
            {
                cout << "No answer" << endl;
                return 0;
            }
            continue;
        }
        g[fi] = fa, r[fi] = r[i] ^ r[a] ^ opt;
    }
    int c = 0, mn = 0, mx = 0; // 方案数=2^并查集数 最大值=所有最大相加 最小值=所有最小相加
    for (int i = 1; i <= n; i++)
    {
        int fi = dfn(i);
        r[i] ? c1[fi]++ : c0[fi]++;
        c += (fi == i);
    }
    cout << qmod(c) << endl;
    for (int i = 1; i <= n; i++)
    {
        mn += min(c1[i], c0[i]), mx += max(c1[i], c0[i]);
    }
    cout << mx << endl;
    cout << mn << endl;
    return 0;
}