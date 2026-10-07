#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double x, ans = 0;
    for (int i = 1; i <= 12; i++)
    {
        cin >> x;
        if (x > 800)
        {
            ans += (x - 800) * 0.2;
        }
    }
    cout << fixed << setprecision(2) << ans << endl;
    return 0;
}