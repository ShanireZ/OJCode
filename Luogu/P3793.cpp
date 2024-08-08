#include <algorithm>
#include <iostream>
using namespace std;
#define MX 20000005
int lc[MX], rc[MX], fa[MX], v[MX], n, m, s, last, root;
namespace GenHelper
{
    unsigned z1, z2, z3, z4, b;
    unsigned rand_()
    {
        b = ((z1 << 6) ^ z1) >> 13;
        z1 = ((z1 & 4294967294U) << 18) ^ b;
        b = ((z2 << 2) ^ z2) >> 27;
        z2 = ((z2 & 4294967288U) << 2) ^ b;
        b = ((z3 << 13) ^ z3) >> 21;
        z3 = ((z3 & 4294967280U) << 7) ^ b;
        b = ((z4 << 3) ^ z4) >> 12;
        z4 = ((z4 & 4294967168U) << 13) ^ b;
        return (z1 ^ z2 ^ z3 ^ z4);
    }
}
void srand(unsigned x)
{
    using namespace GenHelper;
    z1 = x;
    z2 = (~x) ^ 0x233333333U;
    z3 = x ^ 0x1234598766U;
    z4 = (~x) + 51;
}
int read()
{
    using namespace GenHelper;
    int a = rand_() & 32767;
    int b = rand_() & 32767;
    return a * 32768 + b;
}
int main()
{
    cin >> n >> m >> s;
    srand(s);
    v[1] = read(), root = last = 1;
    for (int i = 2; i <= n; i++)
    {
        v[i] = read();
        int ok = 1;
        while (v[last] < v[i]) // 按大小分配层,按先后分配左右
        {
            if (fa[last] == 0)
            {
                fa[last] = i, lc[i] = last, ok = 0, root = i;
                break;
            }
            last = fa[last];
        }
        if (ok)
        {
            fa[i] = last, lc[i] = rc[last];
            rc[last] = i, fa[lc[last]] = i;
        }
        last = i;
    }
    unsigned long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int l = read() % n + 1, r = read() % n + 1;
        if (l > r)
        {
            swap(l, r);
        }
        int now = root;
        while (now < l || now > r)
        {
            now = (now < l ? rc[now] : lc[now]);
        }
        ans = ans + v[now];
    }
    cout << ans << endl;
    return 0;
}