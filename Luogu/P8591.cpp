#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct Edge
{
    int l, r;
    bool operator<(const Edge oth) const
    {
        return l < oth.l;
    }
};
Edge es[3005];
int aft[3005], pre[3005], n;
long long dp[3005], ans = 1e15;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> es[i].l >> es[i].r;
    }
    sort(es + 1, es + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        pre[i] = aft[i] = i;
        for (int j = i - 1; j > 0; j--)
        {
            if (es[i].l > es[j].r)
            {
                break;
            }
            pre[i] = j;
        }
        for (int j = i + 1; j <= n; j++)
        {
            if (es[i].r < es[j].l)
            {
                break;
            }
            aft[i] = j;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0, es[0].l = es[0].r = -1e9 - 7;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (es[i].l <= es[j].r)
            {
                continue;
            }
            if (aft[j] + 1 >= pre[i])
            {
                dp[i] = min(dp[i], dp[j] + es[i].r - es[i].l);
            }
        }
        if (aft[i] == n)
        {
            ans = min(ans, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}