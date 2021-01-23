#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    int x = a[1] - a[0];
    int y = a[2] - a[1];
    int maxd = max(x, y), mind = min(x, y);
    if (mind == 1)
    {
        mind = maxd;
    }
    cout << min(2, mind - 1) << endl
         << maxd - 1;
    return 0;
}