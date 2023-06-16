#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n, x, y, a, b;
    cin >> n >> x >> y >> a >> b;
    long long now = 0, maxn = 0, cnt = 0, pre = -1;
    for (int i = 1; i <= n; i++)
    {
        int S, s, M;
        cin >> S >> s >> M;
        M = M - S * x - s * y;
        if (M != 0)
        {
            now += M;
            if (M > S * x + s * y)
            {
                now += 0.5 * M + 0.6;
            }
            if (pre == 1)
            {
                cnt++;
            }
            else
            {
                cnt = 1, pre = 1;
            }
            if (cnt >= a)
            {
                now *= 2;
            }
            maxn = max(maxn, now);
        }
        else
        {
            if (pre == 0)
            {
                cnt++;
            }
            else
            {
                cnt = 1, pre = 0;
            }
            if (cnt >= b)
            {
                now /= 2;
            }
        }
    }
    cout << maxn << " " << now;
    return 0;
}