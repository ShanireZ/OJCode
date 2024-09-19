#include <algorithm>
#include <iostream>
using namespace std;
int a[1005], b[1005], r[1005], n, x, y, z, ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        if (a[i] == b[i])
        {
            z++;
        }
        else if (a[i] < b[i])
        {
            y++;
            r[y] = b[i] - a[i];
        }
    }
    sort(r + 1, r + 1 + y);
    x = n - y - z;
    while (z && x <= y)
    {
        ans++, x++, z--;
    }
    for (int i = 1; x <= y; i++)
    {
        ans += r[i], x++;
        if (x > y)
        {
            break;
        }
        ans++, y--;
    }
    cout << ans << endl;
    return 0;
}