#include <algorithm>
#include <iostream>
using namespace std;
long long cnt[2000005], tot[2000005];
int main()
{
    for (int i = 1; i <= 2000000; i++)
    {
        cnt[i] = cnt[i - 1] + i;
        tot[i] = tot[i - 1] + cnt[i];
    }
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, ans = 0;
        cin >> l >> r;
        int pl = lower_bound(cnt + 1, cnt + 2000001, l) - cnt;
        int pr = upper_bound(cnt + 1, cnt + 2000001, r) - cnt;
        ans = tot[pr - 1] - tot[pl - 1];
        ans += (r - cnt[pr - 1]) * (r - cnt[pr - 1] + 1) / 2;
        ans -= (l - cnt[pl - 1] - 1) * (l - cnt[pl - 1]) / 2;
        cout << ans << "\n";
    }
    return 0;
}