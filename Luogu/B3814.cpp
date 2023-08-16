#include <algorithm>
#include <iostream>
using namespace std;
int ms[10][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
int main()
{
    int sx, sy, cx, cy, mx, my;
    cin >> sx >> sy >> cx >> cy >> mx >> my;
    for (int i = 0; i < 8; i++)
    {
        int nx = mx + ms[i][0], ny = my + ms[i][1];
        if (nx < 1 || ny < 1 || nx > 10 || ny > 9)
        {
            continue;
        }
        int x1 = min(abs(sx - nx), abs(sy - ny)), x2 = max(abs(sx - nx), abs(sy - ny));
        int x3 = min(abs(cx - nx), abs(cy - ny)), x4 = max(abs(cx - nx), abs(cy - ny));
        if (x1 == 1 && x2 == 2 && x3 == 1 && x4 == 2)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}