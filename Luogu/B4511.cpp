#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int r1, r2, d, ans = 0;
    cin >> r1 >> r2 >> d;
    if (r1 == r2 && d == 0)
    {
        cout << "inf" << endl;
        return 0;
    }
    int c1 = max(r1 - r2, r2 - r1), c2 = r1 + r2;
    if (c1 == d)
    {
        ans = 1;
    }
    else if (c1 < d && d < c2)
    {
        ans = 2;
    }
    else if (c2 == d)
    {
        ans = 3;
    }
    else if (c2 < d)
    {
        ans = 4;
    }
    else if (c1 > d)
    {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}