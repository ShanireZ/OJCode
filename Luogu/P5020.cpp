#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dp[25005], num[105];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans;
        cin >> n;
        ans = n;
        for (int i = 1; i <= n; i++)
        {
            cin >> num[i];
        }
        sort(num + 1, num + 1 + n);
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            int ok = 0;
            for (int j = num[i]; j <= num[n]; j++)
            {
                if (dp[j])
                {
                    continue;
                }
                else if (dp[j - num[i]])
                {
                    ok = 1;
                    dp[j] = 1;
                }
            }
            if (ok == 0)
            {
                ans--;
            }
        }
        cout << ans << endl;
    }
    return 0;
}