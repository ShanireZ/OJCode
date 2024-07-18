#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int a[25], dp[100005];
string s;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 33333; i++)
    {
        for (int j = 1; j <= n && j <= i; j++)
        {
            dp[i] = max(dp[i], a[j] + dp[i - j]);
        }
    }
    int m, cnt = 0, p = 0, ans = 0;
    cin >> m >> s;
    while (p < m)
    {
        if (p + 2 < m && s.substr(p, 3) == "abc")
        {
            cnt++, p += 3;
        }
        else
        {
            ans += dp[cnt], cnt = 0, p++;
        }
    }
    ans += dp[cnt];
    cout << ans << endl;
    return 0;
}