#include <cstring>
#include <iostream>
using namespace std;
int v[25], h[105], dp[100005];
int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= b; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= b; i++)
    {
        for (int j = v[i]; j <= 100000; j++)
        {
            dp[j] = min(dp[j], dp[j - v[i]] + 1);
        }
    }
    int ok = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int c = h[i] - h[i - 1];
        if (ok == 0 && c != 0)
        {
            ok = 1;
            ans += dp[c];
        }
        else if (ok == 1 && c != -1)
        {
            ans += dp[c + 1];
        }
    }
    cout << ans << endl;
    return 0;
}