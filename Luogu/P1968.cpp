#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double dp1 = 100, dp2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        dp2 = max(dp2, dp1 / 100 * x);
        dp1 = max(dp1, dp2 / x * 100);
    }
    cout << fixed << setprecision(2) << dp1 << endl;
    return 0;
}