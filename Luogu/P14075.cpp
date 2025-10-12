#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
long long a[100005], dp[100005], vis[30], n;
string str;
int main()
{
    cin >> n >> str;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    str = "#" + str;
    for (int i = 1; i <= n; i++)
    {
        fill(vis, vis + 26 + 1, 0);
        for (int j = i - 1; j >= 0; j--) // 前一段的结尾
        {
            if (vis[str[j + 1] - 'a'] == 1)
            {
                break;
            }
            vis[str[j + 1] - 'a'] = 1;
            dp[i] = max(dp[i], dp[j] + a[i - j]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}