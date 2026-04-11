#include <algorithm>
#include <iostream>
using namespace std;
int n, x, y, ans, now, t, sta, c[10005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    c[0] = -1;
    cin >> x >> y;
    for (int i = 1; i <= n; i++)
    {
        if (sta == 0)
        {
            if (c[i] == 0)
            {
                now = (now + 3) % 4;
            }
            else if (c[i] == 1)
            {
                now = (now + 1) % 4;
            }
            else
            {
                now = (now + 2) % 4;
            }
            ans += (now == 2);
            t = (c[i] == c[i - 1] ? t + 1 : 1);
            if (t == x && c[i] != 2)
            {
                t = y, sta = 1;
            }
        }
        else
        {
            now = (now + 2) % 4;
            ans += (now == 2), t--;
        }
        if (sta && t == 0)
        {
            sta = 0;
        }
    }
    cout << ans << endl;
    return 0;
}