#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long ans = 0, a, b, c, d, e, f, g, p, x1, x2, y1, y2;
    cin >> a >> b >> c >> d >> e >> f >> g >> p >> x1 >> x2 >> y1 >> y2;
    for (int x = x1; x <= x2; x++)
    {
        for (int y = y1; y <= y2; y++)
        {
            ans = max(ans, (a * x * x * x % p + b * y * y * y % p + c * x * x * y % p + d * x * y * y % p + e * x * y % p + f * x % p + g * y % p) % p);
        }
    }
    cout << ans << endl;
    return 0;
}