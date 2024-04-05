#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, k, ans;
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        long long maxc = -1e15;
        for (int j = 1; j <= m; j++)
        {
            long long x;
            cin >> x;
            maxc = max(maxc, x - k * j);
        }
        ans += maxc;
    }
    cout << ans << endl;
    return 0;
}