#include <algorithm>
#include <iostream>
using namespace std;
long long n, x0, y00, x1, y11;
long long lx, ly, rx = 1e18, ry = 1e18;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x0 >> y00 >> x1 >> y11;
        lx = max(lx, x0), ly = max(ly, y00);
        rx = min(rx, x1), ry = min(ry, y11);
    }
    lx = max(0ll, lx - rx), ly = max(0ll, ly - ry);
    cout << max(lx, ly) << endl;
    return 0;
}