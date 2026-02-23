#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<long long> all[200005], sum[200005];
long long n, m, q, qz[200005];
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> qz[i] >> a;
        all[a].push_back(i), sum[a].push_back(qz[i]);
        qz[i] += qz[i - 1];
        if (sum[a].size() > 1)
        {
            sum[a][(int)sum[a].size() - 1] += sum[a][(int)sum[a].size() - 2];
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        long long ans = qz[r] - qz[l - 1];
        int p1 = lower_bound(all[t].begin(), all[t].end(), l) - all[t].begin();
        int p2 = upper_bound(all[t].begin(), all[t].end(), r) - all[t].begin() - 1;
        if (p2 >= 0)
        {
            long long delta = sum[t][p2];
            if (p1 > 0)
            {
                delta -= sum[t][p1 - 1];
            }
            ans -= delta / 2;
        }
        cout << ans << endl;
    }
    return 0;
}