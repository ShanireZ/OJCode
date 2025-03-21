#include <algorithm>
#include <iostream>
using namespace std;
long long n, op, res, x[1000005], y[1000005];
int main()
{
    cin >> n >> op;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    if (op == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                res = max(res, (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            }
        }
    }
    else
    {
        for (int i = 1; i <= n; i++) // 曼哈顿距离转化切比雪夫距离
        {
            int nx = x[i] + y[i], ny = x[i] - y[i];
            x[i] = nx, y[i] = ny;
        }
        sort(x + 1, x + n + 1), sort(y + 1, y + n + 1);
        res = max(x[n] - x[1], y[n] - y[1]);
    }
    cout << res << endl;
    return 0;
}