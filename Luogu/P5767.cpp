#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int dp[505][505], rec[505], n, m;
string s;
int main()
{
    cin >> m >> n;
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    getline(cin, s);
    for (int i = 1; i <= m; i++)
    {
        getline(cin, s);
        int pos = 0, num = 0;
        for (char c : s)
        {
            if (isdigit(c))
            {
                num = num * 10 + c - '0';
            }
            else if (num > 0)
            {
                rec[++pos] = num;
                num = 0;
            }
        }
        if (num > 0)
        {
            rec[++pos] = num;
        }
        for (int j = 1; j <= pos; j++)
        {
            for (int k = j + 1; k <= pos; k++)
            {
                dp[rec[j]][rec[k]] = min(dp[rec[j]][rec[k]], 1);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    if (dp[1][n] == 0x3f3f3f3f)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << dp[1][n] - 1 << endl;
    }
    return 0;
}