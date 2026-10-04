#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<pair<int, int>, int> m;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int dx = c - a, dy = d - b;
        int g = __gcd(abs(dx), abs(dy));
        dx /= g, dy /= g;
        for (int t = 0, x = a, y = b; t <= g; t++, x += dx, y += dy)
        {
            ans += (m[{x, y}] == 1);
            m[{x, y}]++;
        }
    }
    cout << ans << endl;
    return 0;
}