#include <iostream>
using namespace std;
long long cnt[200][200], ans, now, t;
int main()
{
    int d, n;
    cin >> d >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        cnt[x][y] = k;
    }
    for (int i = 0; i <= 128; i++) // 枚举投放区域中心
    {
        for (int j = 0; j <= 128; j++)
        {
            now = 0;
            for (int x = max(0, i - d); x <= min(128, i + d); x++) // 遍历投放区域
            {
                for (int y = max(0, j - d); y <= min(128, j + d); y++)
                {
                    now += cnt[x][y];
                }
            }
            if (ans == now)
            {
                t++;
            }
            else if (ans < now)
            {
                t = 1, ans = now;
            }
        }
    }
    cout << t << " " << ans << endl;
    return 0;
}