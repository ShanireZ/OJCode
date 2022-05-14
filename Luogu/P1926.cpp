#include <algorithm>
#include <iostream>
using namespace std;
int dp[200], pb[20];
struct HW
{
    int t, s;
};
HW hs[20];
int main()
{
    int n, m, k, r;
    cin >> n >> m >> k >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> pb[i];
    }
    sort(pb + 1, pb + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        cin >> hs[i].t;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> hs[i].s;
        for (int j = r; j >= hs[i].t; j--)
        {
            dp[j] = max(dp[j], dp[j - hs[i].t] + hs[i].s);
        }
    }
    for (int i = 0; i <= r; i++)
    {
        if (dp[i] >= k)
        {
            r -= i;
            break;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (r >= pb[i])
        {
            r -= pb[i];
            cnt++;
        }
        else
        {
            break;
        }
    }
    cout << cnt << endl;
    return 0;
}