#include <algorithm>
#include <iostream>
using namespace std;
int mth[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int y, m, d, h, k;
    cin >> y >> m >> d >> h >> k;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
    {
        mth[2] = 29;
    }
    h += k;
    if (h >= 24)
    {
        d++, h -= 24;
    }
    if (d > mth[m])
    {
        d -= mth[m];
        m++;
    }
    if (m > 12)
    {
        m -= 12;
        y++;
    }
    cout << y << " " << m << " " << d << " " << h << endl;
    return 0;
}