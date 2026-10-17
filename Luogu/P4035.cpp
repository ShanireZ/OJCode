#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
double pos[15][15], dis[15], add[15];
int n;
double count(int x, int y)
{
    double tot = 0;
    for (int i = 1; i <= n; i++)
    {
        tot += (pos[x][i] - pos[y][i]) * (pos[x][i] - pos[y][i]);
    }
    return sqrt(tot);
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> pos[i][j];
            pos[13][j] += pos[i][j] / (n + 1); // 初始值為平均值
        }
    }
    for (double t = 10000; t > 1e-6; t *= 0.99995)
    {
        double avg = 0;
        for (int i = 1; i <= n + 1; i++)
        {
            dis[i] = count(13, i);
            avg += dis[i] / (n + 1), add[i] = 0;
        }
        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // 當前到第i個點距離和平均值的差距比例 * 兩點之間的距離 * t溫度係數
                // 差距比例越大，移動距離越大；溫度越高，移動距離越大
                add[j] += (dis[i] - avg) / avg * (pos[i][j] - pos[13][j]) * t;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            pos[13][i] += add[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << fixed << setprecision(3) << pos[13][i] << " ";
    }
    return 0;
}
// TAG: 高斯消元 模擬退火 爬山