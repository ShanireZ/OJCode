#include <algorithm>
#include <iostream>
using namespace std;
int x[705], y[705];
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int vx = x[j] - x[i], vy = y[j] - y[i], res = 2;
            for (int k = j + 1; k <= n; k++)
            {
                int ovx = x[k] - x[i], ovy = y[k] - y[i];
                res += (vx * ovy == vy * ovx); // 向量共线 x1y2 = x2y1
            }
            ans = max(ans, res);
        }
    }
    cout << ans << endl;
    return 0;
}