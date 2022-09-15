#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
struct Node
{
    int x, y, s;
};
Node ns[200005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ns[i].x >> ns[i].y >> ns[i].s;
    }
    long double l = 0.01, r = 1e9;
    while (l <= r)
    {
        long double mid = (l + r) / 2, now = 0;
        bool ok = 1;
        for (int i = 1; i <= n; i++)
        {
            now = now + ns[i].s / mid;
            if (now > ns[i].y)
            {
                ok = 0;
                break;
            }
            now = max(now, (long double)1.0 * ns[i].x);
        }
        if (ok)
        {
            r = mid - 0.0001;
        }
        else
        {
            l = mid + 0.0001;
        }
    }
    cout << fixed << setprecision(2) << l << endl;
    return 0;
}