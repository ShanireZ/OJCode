#include <iostream>
using namespace std;
#define MX 1000005
int g[MX], r[MX], c1[MX], c0[MX], mod = 998244353, n;
// r[i]:i與上級間是否同調 1:同調 0:不同調
int dfn(int x)
{
    if (x != g[x])
    {
        int fx = g[x];          // 保存原上層節點編號
        g[x] = dfn(g[x]);       // 路徑壓縮回傳後,上層的同調性已更新
        r[x] = (r[x] == r[fx]); // 更新自己的同調性
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
        cin >> a >> opt; // opt=1:同調 opt=0:不同調
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
    int c = 0, mn = 0, mx = 0; // 方案數=2^並查集數 最大值=所有最大相加 最小值=所有最小相加
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