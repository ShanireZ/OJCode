#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long t, n, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n >> x >> y;
        long long ans = max(y - x + 1, 0ll);
        cout << ans << endl;
    }
    return 0;
}