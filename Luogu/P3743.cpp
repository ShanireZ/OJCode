#include <algorithm>
#include <iostream>
using namespace std;
int a[100005], b[100005];
int main()
{
    int n, p;
    cin >> n >> p;
    long long all = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        all += a[i];
    }
    if (p >= all)
    {
        cout << -1 << endl;
        return 0;
    }
    double L = 0, R = 1e10;
    while (R - L >= 1e-6)
    {
        double mid = (L + R) / 2, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] * mid > b[i])
            {
                tot += a[i] * mid - b[i];
            }
        }
        tot > mid *p ? R = mid : L = mid;
    }
    cout << R << endl;
    return 0;
}
// TAG: 二分答案