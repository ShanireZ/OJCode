#include <iostream>
using namespace std;
int gx[20][20], dp[20], cnt[20][20];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> gx[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 1; j--) // dp位置
        {
            for (int k = 1; k <= j; k++) // 第i个公司机器数量
            {
                if (dp[j - k] + gx[i][k] >= dp[j]) // 字典序尽可能大
                {
                    dp[j] = dp[j - k] + gx[i][k];
                    for (int x = 1; x < i; x++)
                    {
                        cnt[j][x] = cnt[j - k][x];
                    }
                    cnt[j][i] = k;
                }
            }
        }
    }
    cout << dp[m] << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << i << " " << cnt[m][i] << endl;
    }
    return 0;
}