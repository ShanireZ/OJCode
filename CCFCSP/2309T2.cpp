#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
double d1[100005], d2[100005];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    fill(d1, d1 + n + 1, 1);
    for (int i = 1; i <= n; i++)
    {
        int opt;
        double d;
        cin >> opt >> d;
        opt == 1 ? d1[i] *= d : d2[i] += d;
    }
    for (int i = 1; i <= n; i++)
    {
        d1[i] *= d1[i - 1], d2[i] += d2[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        double x, y;
        cin >> l >> r >> x >> y;
        x = x * d1[r] / d1[l - 1], y = y * d1[r] / d1[l - 1];
        double xx = cos(d2[r] - d2[l - 1]) * x - sin(d2[r] - d2[l - 1]) * y;
        double yy = sin(d2[r] - d2[l - 1]) * x + cos(d2[r] - d2[l - 1]) * y;
        cout << fixed << setprecision(1) << xx << " " << yy << '\n';
    }
    return 0;
}