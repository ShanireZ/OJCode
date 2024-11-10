#include <algorithm>
#include <iostream>
using namespace std;
long long z[105], a[105], b[105];
int main()
{
    long long n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> z[i] >> a[i] >> b[i];
    }
    long long l = 1, r = 1e12;
    while (l <= r)
    {
        long long mid = (l + r) / 2, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (mid > z[i])
            {
                tot += a[i] * z[i] + b[i] * (mid - z[i]);
            }
            else
            {
                tot += a[i] * mid;
            }
        }
        tot >= p ? r = mid - 1 : l = mid + 1;
    }
    cout << l << endl;
    return 0;
}