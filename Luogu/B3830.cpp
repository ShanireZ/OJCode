#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, x, pre = 0, ans = 1e18 + 7;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        long long c;
        cin >> c;
        if (x + 1 > c || (i > 1 && (c - pre) % x != 0))
        {
            cout << -1 << "\n";
            return 0;
        }
        ans = min(ans, c);
        pre = c;
    }
    cout << ans - x << "\n";
    return 0;
}