#include <iomanip>
#include <iostream>
using namespace std;
int h[10005], n, w;
int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        cin >> h[i];
    }
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> w;
        ans += w * (h[i - 1] + h[i]) / 2.0;
    }
    cout << fixed << setprecision(1) << ans << "\n";
    return 0;
}