#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long x1, y1, x2, y2, x3, y3, x4, y4, ans = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if (x1 > x3 || x3 > x2)
        {
            ans++;
        }
        if (y1 < y3 || y1 > y4)
        {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}