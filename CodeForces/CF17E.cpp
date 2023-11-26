#include <algorithm>
#include <iostream>
using namespace std;
#define MX 4000005
#define MXH 2000005
#define MOD 51123987
long long st[MXH], ed[MXH], ans, tot;
char s[MX], c;
int p[MX], n, mx, mid, pos;
int main()
{
    s[++pos] = '#';
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[++pos];
        s[++pos] = '#';
    }
    for (int i = 1; i <= pos; i++)
    {
        p[i] = (i < mx ? min(p[2 * mid - i], mx - i) : 1);
        while (i - p[i] >= 1 && i + p[i] <= pos && s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > mx)
        {
            mx = i + p[i], mid = i;
        }
        if (p[i] != 1)
        {
            int lmid, rmid, l, r, len = p[i] - 1;
            if (i % 2 == 0)
            {
                lmid = rmid = i / 2;
                l = lmid - len / 2, r = rmid + len / 2;
            }
            else
            {
                lmid = (i - 1) / 2, rmid = (i + 1) / 2;
                l = lmid - len / 2 + 1, r = rmid + len / 2 - 1;
            }
            st[l]++, st[lmid + 1]--, ed[rmid]++, ed[r + 1]--; // 差分
        }
    }
    for (int i = 1; i <= n + 1; i++) // 求原值
    {
        st[i] = (st[i] + st[i - 1]) % MOD;
        ed[i] = (ed[i] + ed[i - 1]) % MOD;
        tot = (tot + st[i]) % MOD;
    }
    tot = tot * (tot - 1) / 2 % MOD;
    for (int i = 1; i <= n; i++) // 求前缀和
    {
        ed[i] = (ed[i] + ed[i - 1]) % MOD;
    }
    for (int i = 1; i <= n; i++) // 求不相交的-->开始在其他串终点后
    {
        ans = (ans + ed[i] * st[i + 1] % MOD) % MOD;
    }
    cout << (tot - ans + MOD) % MOD << endl;
    return 0;
}
// TAG: manacher 差分 前缀和