#include <iostream>
#include <vector>
using namespace std;
int dp[1500];
vector<int> vb, hb;
int main()
{
    int n, t, k;
    cin >> n >> t >> k;
    for (int i = 1; i <= n; i++)
    {
        int v, h;
        cin >> v >> h;
        for (int j = h; j <= t * 5 / 4; j++)
        {
            dp[j] = max(dp[j], dp[j - h] + v);
        }
        if (h >= k)
        {
            vb.push_back(v), hb.push_back(h);
        }
    }
    int ans = dp[t];
    for (int i = 0; i < vb.size(); i++)
    {
        ans = max(ans, dp[(t - hb[i]) * 5 / 4] + vb[i]);
    }
    cout << ans << endl;
    return 0;
}