#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    int ans = (abs(x) == abs(y) ? 1 : 0x7f7f7f7f);
    if (x < y)
    {
        ans = min(ans, y - x);
        if (-x < y)
        {
            ans = min(ans, y + x + 1);
        }
        if (x < -y)
        {
            ans = min(ans, -y - x + 1);
        }
    }
    else if (x > y)
    {
        ans = min(ans, abs(x) > abs(y) ? y + x + 1 : -y - x + 1);
        if ((x <= 0 && y <= 0) || (x >= 0 && y >= 0))
        {
            ans = min(ans, -y + x + 2);
        }
    }
    cout << ans << endl;
    return 0;
}