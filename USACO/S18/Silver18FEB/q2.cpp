#include <iostream>
#include <algorithm>
using namespace std;
int dp[255][255]; //dp[a][b] 表示第a个位置穿着b是否可以到达
int f[255], s[255], d[255];
int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }
    for (int i = 1; i <= b; i++)
    {
        cin >> s[i] >> d[i];
    }
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (dp[i][j])
            {
                for (int k = j; k <= b; k++)
                {
                    if (s[k] >= f[i])
                    {
                        dp[i][k] = 1;
                        for (int dis = i + 1; dis <= n && dis <= i + d[k]; dis++)
                        {
                            if (s[k] >= f[dis])
                            {
                                dp[dis][k] = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i <= b; i++)
    {
        if (dp[n][i])
        {
            cout << i - 1;
            break;
        }
    }
    return 0;
}