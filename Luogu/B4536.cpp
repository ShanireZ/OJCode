#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, m, p, q, t, ans = 1e9;
    cin >> a >> b >> c >> m >> p >> q >> t;
    if (a + b + m < t)
    {
        ans = min(ans, p);
    }
    if (a + c + m < t)
    {
        ans = min(ans, q);
    }
    if (ans == 1e9)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << (ans == p ? p : q) << endl;
        cout << (ans == p ? "bus" : "taxi") << endl;
    }
    return 0;
}