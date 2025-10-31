#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n, x;
    cin >> n;
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        ans += (x + 69) / 70 * 0.1;
    }
    cout << fixed << setprecision(1) << ans << endl;
    return 0;
}