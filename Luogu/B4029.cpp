#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, y, w, k;
    cin >> x >> y >> w >> k;
    int tot = 0, day = 0;
    while (tot < k)
    {
        day++;
        tot += int(1.0 * day / w) + (day >= x) * y;
    }
    cout << day << endl;
    return 0;
}