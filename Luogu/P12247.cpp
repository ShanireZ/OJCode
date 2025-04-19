#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
multiset<long long> st;
vector<long long> add[500005], red[500005];
long long n, m, k, dp[500005], mx[500005];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        long long l, r, w;
        cin >> l >> r >> w;
        if (r - l + 1 >= k)
        {
            add[l].emplace_back(w);
            red[r - k + 2].emplace_back(w);
        }
    }
    for (int t = 1; t <= m - k + 1; t++)
    {
        for (int i = 0; i < (int)add[t].size(); i++)
        {
            st.emplace(add[t][i]);
        }
        for (int i = 0; i < (int)red[t].size(); i++)
        {
            auto it = st.lower_bound(red[t][i]);
            st.erase(it);
        }
        if (st.size())
        {
            mx[t] = *(--st.end());
        }
    }
    for (int t = 1; t <= m; t++)
    {
        if (t <= m - k + 1)
        {
            dp[t + k - 1] = max(dp[t + k - 1], dp[t - 1] + mx[t]);
        }
        dp[t] = max(dp[t], dp[t - 1]);
    }
    cout << dp[m] << "\n";
    return 0;
}