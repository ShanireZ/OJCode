#include <algorithm>
#include <iostream>
using namespace std;
int n, sum[105][105]; // sum[i][j]:前i行第j列之和
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            sum[i][j] = sum[i - 1][j] + a;
        }
    }
    int ans = -1e9;
    for (int i = 1; i <= n; i++) // 矩阵上端行号
    {
        for (int j = i; j <= n; j++) // 矩阵下端行号
        {
            int pre = 0;
            for (int k = 1; k <= n; k++) // 枚举每列
            {
                int dp = sum[j][k] - sum[i - 1][k];
                pre + dp > dp ? pre += dp : pre = dp;
                ans = max(ans, pre);
            }
        }
    }
    cout << ans << endl;
    return 0;
}