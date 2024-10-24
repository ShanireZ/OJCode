#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m, p, ans = 0;
    cin >> n >> m >> p;
    for (int y = 1; y < m; y++)
    {
        int l = n * y / m + 1;                         // x=ny/m 向下取整再+1
        int r = (y * (n - p) + m * p + m - 1) / m - 1; // x=(y(n-p)+mp)/m 向上取整再-1
        if (r >= l)
        {
            ans += r - l + 1;
        }
    }
    cout << ans << endl;
    return 0;
}