#include <algorithm>
#include <iostream>
using namespace std;
long long h[1000005], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }
    long long L = 0, R = 1e9;
    while (L <= R)
    {
        long long mid = (L + R) / 2, tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (h[i] > mid)
            {
                tot += h[i] - mid;
            }
        }
        (tot >= m) ? (L = mid + 1) : (R = mid - 1);
    }
    cout << R << endl;
    return 0;
}