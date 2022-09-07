#include <algorithm>
#include <iostream>
using namespace std;
#define MX 5005
struct Node
{
    int w, h, id;
    bool operator<(const Node oth) const
    {
        return w < oth.w;
    }
};
Node ns[MX];
int dp[MX], pre[MX], ans[MX], p;
int main()
{
    int n, sz = 0;
    cin >> n >> ns[0].w >> ns[0].h;
    for (int i = 1; i <= n; i++)
    {
        int w, h;
        cin >> w >> h;
        if (w > ns[0].w && h > ns[0].h)
        {
            ns[++sz].w = w;
            ns[sz].h = h, ns[sz].id = i;
        }
    }
    sort(ns + 1, ns + 1 + sz);
    int pos = 0;
    for (int i = 1; i <= sz; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (ns[i].w > ns[j].w && ns[i].h > ns[j].h && dp[j] + 1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                pre[i] = j;
            }
        }
        if (dp[i] > dp[pos])
        {
            pos = i;
        }
    }
    cout << dp[pos] << endl;
    if (dp[pos])
    {
        while (pos != 0)
        {
            ans[++p] = ns[pos].id;
            pos = pre[pos];
        }
        for (int i = p; i >= 1; i--)
        {
            cout << ans[i] << " ";
        }
    }
    return 0;
}