#include <cmath>
#include <iostream>
using namespace std;
long long tot[200005];
int main()
{
    int n;
    cin >> n;
    long long tmin = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> tot[i];
        tot[i] += tot[i - 1];
        long long now = ceil(1.0 * tot[i] / i);
        tmin = max(tmin, now);
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        long long t;
        cin >> t;
        if (t < tmin)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << (long long)(ceil(1.0 * tot[n] / t)) << '\n';
        }
    }
    return 0;
}