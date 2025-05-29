#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            ans += (i + j >= x || i - j >= y || j - i >= y);
        }
    }
    cout << fixed << setprecision(10) << ans / 36.0 << endl;
    return 0;
}