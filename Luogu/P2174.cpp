#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
#define MOD 317847191
#define MX 1000005
char op[MX];
int del[MX], a[MX], all[MX], cnt[MX], ans[MX];
int quickm(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b % 2 == 1)
        {
            ans = ans * a % MOD;
        }
        a = a * a % MOD, b /= 2;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        all[i] = a[i];
    }
    sort(all + 1, all + n + 1);
    int sz = unique(all + 1, all + 1 + n) - all - 1;
    for (int i = 1; i <= n; i++)
    {
        int p = lower_bound(all + 1, all + 1 + sz, a[i]) - all;
        cnt[p]++;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> op[i];
        if (op[i] == 'D')
        {
            cin >> del[i];
            int p = lower_bound(all + 1, all + 1 + sz, del[i]) - all;
            cnt[p]--;
        }
        ans[i] = -1;
    }
    long long mul = 1, mx = 0, mn = 1e9;
    for (int i = 1; i <= sz; i++)
    {
        if (cnt[i] == 0)
        {
            continue;
        }
        for (int j = 1; j <= cnt[i]; j++)
        {
            mul = mul * all[i] % MOD;
        }
        mx = all[i];
        if (mn == 1e9)
        {
            mn = all[i];
        }
    }
    for (int i = m; i >= 1; i--)
    {
        if (op[i] == 'T')
        {
            ans[i] = mul;
        }
        else if (op[i] == 'B')
        {
            ans[i] = mx;
        }
        else if (op[i] == 'S')
        {
            ans[i] = mn;
        }
        else if (op[i] == 'M')
        {
            ans[i] = quickm(mx, mn);
        }
        else
        {
            int p = lower_bound(all + 1, all + 1 + sz, del[i]) - all;
            if (cnt[p] == 0)
            {
                mx = max(mx, (long long)all[p]);
                mn = min(mn, (long long)all[p]);
            }
            cnt[p]++, mul = mul * all[p] % MOD;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (ans[i] != -1)
        {
            cout << ans[i] << "\n";
        }
    }
    return 0;
}