#include <algorithm>
#include <iostream>
using namespace std;
int r, b, c, d, e;
int main()
{
    cin >> r >> b >> c >> d >> e;
    int ans = r * c + b * d, mn = min(r, b);
    ans = max(ans, mn * 2 * e + (r - mn) * c + (b - mn) * d);
    cout << ans << endl;
    return 0;
}