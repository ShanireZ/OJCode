#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, k, t[100005], c[100005];
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> t[i] >> c[i];
    }
    long long l = k, r = 1e5;
    while (l <= r)
    {
        long long mid = (l + r) / 2, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (t[i] > mid)
            {
                tot += c[i] * (t[i] - mid);
            }
        }
        tot <= m ? r = mid - 1 : l = mid + 1;
    }
    cout << l << endl;
    return 0;
}