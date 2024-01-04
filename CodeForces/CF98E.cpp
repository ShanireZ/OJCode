#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;
double dp[1005][1005];
double makeans(int x, int y)
{
    if (dp[x][y])
    {
        return dp[x][y];
    }
    if (x == 0)
    {
        return dp[x][y] = 1.0 / (y + 1.0);
    }
    if (y == 0)
    {
        return dp[x][y] = 1.0;
    }
    // a* p + c * (1- p) == b * p + d * (1 - p)
    double a = y / (y + 1.0) * (1.0 - makeans(y - 1, x));
    double b = a + 1.0 / (y + 1.0);
    double c = 1.0, d = 1.0 - makeans(y, x - 1);
    double p = (d - c) / (a - b - c + d);
    return dp[x][y] = p * a + (1.0 - p) * c;
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << fixed << setprecision(9) << makeans(n, m) << " " << 1 - makeans(n, m) << endl;
    return 0;
}
// TAG: 纳什均衡 博弈论