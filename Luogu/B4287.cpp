#include <algorithm>
#include <iostream>
using namespace std;
int a[105][105], n, res;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int sx, sy, fx, fy;
        cin >> sx >> sy >> fx >> fy;
        for (int x = sx; x < fx; x++)
        {
            for (int y = sy; y < fy; y++)
            {
                a[x][y] = 1;
            }
        }
    }
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            res += a[x][y];
        }
    }
    cout << res << endl;
    return 0;
}