#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
double d[200][200];
double maxd[200];
int p[200][2];
double cnt(int a, int b)
{
    return sqrt(pow(p[a][0] - p[b][0], 2) + pow(p[a][1] - p[b][1], 2));
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) //! 讀入位置 n
    {
        cin >> p[i][0] >> p[i][1];
    }
    for (int i = 1; i <= n; i++) //! 讀入連接性 初始化距離 n ^ 2
    {
        for (int j = 1; j <= n; j++)
        {
            char link;
            cin >> link;
            if (link == '1')
            {
                d[i][j] = d[j][i] = cnt(i, j);
            }
            else if (i != j)
            {
                d[i][j] = d[j][i] = 0x3f3f3f3f;
            }
        }
    }
    for (int k = 1; k <= n; k++) //! floyd演算法更新距離 n ^ 3
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    double ans1 = 0;
    for (int i = 1; i <= n; i++) //! 找到每個點的最遠距離和當前直徑最大值
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] != 0x3f3f3f3f)
            {
                maxd[i] = max(maxd[i], d[i][j]);
            }
        }
        ans1 = max(ans1, maxd[i]);
    }
    //! 嘗試連接所有不相連的點 假設a和c不連接 此時連接a和c
    //! 假設和a連接的點最遠是b 和c連接的點最遠是d
    //! 連接後此時可能的新直徑最小值為b~a + c~d + a~c
    //! 最小直徑為 max(新直徑的最小值, 連接前直徑的最大值)
    double ans2 = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (d[i][j] == 0x3f3f3f3f)
            {
                ans2 = min(ans2, maxd[i] + maxd[j] + cnt(i, j));
            }
        }
    }
    cout << fixed << setprecision(6) << max(ans1, ans2);
    return 0;
}