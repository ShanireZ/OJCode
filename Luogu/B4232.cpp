#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x1, y1, x2, y2, x3, y3, x4, y4, ans = 0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    if (x1 == x2)
    {
        ans = (abs(y1 - y2) + abs(y3 - y4)) * abs(x1 - x3) / 2;
    }
    else if (x1 == x3)
    {
        ans = (abs(y1 - y3) + abs(y2 - y4)) * abs(x1 - x2) / 2;
    }
    else
    {
        ans = (abs(y1 - y4) + abs(y2 - y3)) * abs(x1 - x2) / 2;
    }
    cout << ans << endl;
    return 0;
}