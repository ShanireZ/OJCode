#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int sx, sy, fx, fy, n;
    cin >> sx >> sy >> fx >> fy >> n;
    int x = fx - sx, y = fy - sy, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        char f;
        cin >> f;
        if (x > 0 && f == 'E')
        {
            x--, cnt++;
        }
        else if (x < 0 && f == 'W')
        {
            x++, cnt++;
        }
        if (y > 0 && f == 'N')
        {
            y--, cnt++;
        }
        else if (y < 0 && f == 'S')
        {
            y++, cnt++;
        }
    }
    if (x == 0 && y == 0)
    {
        cout << cnt << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}