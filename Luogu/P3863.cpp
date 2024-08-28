#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
#define MX 100005
struct Quest
{
    int opt, p, v, t;
    bool operator<(const Quest &oth) const
    {
        return p == oth.p ? t < oth.t : p < oth.p;
    }
};
Quest qs[MX * 2];
int n, m, len, qpos, opos, a[MX], ans[MX], blk[MX], op2[MX];
long long sum[325], ex[MX];
vector<long long> all[325];
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    len = pow(m, 0.5);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int opt, l, r, x;
        cin >> opt >> l >> r;
        if (opt == 1) // 将修改做成差分,可使修改具有永久性
        {
            cin >> x;
            qs[++qpos] = Quest{opt, l, x, i};
            if (r != n)
            {
                qs[++qpos] = Quest{opt, r + 1, -x, i};
            }
        }
        else
        {
            qs[++qpos] = Quest{opt, l, r, i}, op2[++opos] = i;
        }
        blk[i] = (i - 1) / len + 1;
        all[blk[i]].emplace_back(0);
    }
    all[0].emplace_back(0);
    sort(qs + 1, qs + qpos + 1);
    for (int i = 1, pos = 0; i <= qpos; i++)
    {
        if (qs[i].p != pos) // 继承上个位置的修改
        {
            for (int j = 0; j <= blk[m]; j++)
            {
                sum[j] += a[qs[i].p] - a[pos];
            }
            pos = qs[i].p;
        }
        if (qs[i].opt == 1)
        {
            int l = blk[qs[i].t], r = blk[m];
            int ed = (l == r ? m : l * len);
            for (int j = qs[i].t; j <= ed; j++)
            {
                ex[j] += qs[i].v;
            }
            for (int j = l + 1; j <= r; j++)
            {
                sum[j] += qs[i].v;
            }
            all[l].clear();
            for (int j = (l - 1) * len + 1; j <= ed; j++)
            {
                all[l].emplace_back(ex[j]);
            }
            sort(all[l].begin(), all[l].end());
        }
        else
        {
            int l = 0, r = blk[qs[i].t];
            for (int j = l; j <= r - 1; j++)
            {
                ans[qs[i].t] += all[j].end() - lower_bound(all[j].begin(), all[j].end(), qs[i].v - sum[j]);
            }
            for (int j = (r - 1) * len + 1; j < qs[i].t; j++)
            {
                if (ex[j] + sum[r] >= qs[i].v)
                {
                    ans[qs[i].t]++;
                }
            }
        }
    }
    for (int i = 1; i <= opos; i++)
    {
        cout << ans[op2[i]] << '\n';
    }
    return 0;
}
// TAG: 分块 二分查找 贪心