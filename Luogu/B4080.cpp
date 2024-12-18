#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, x, res = 0;
    cin >> a >> b >> c >> d >> x;
    if (x >= a)
    {
        res += b;
    }
    if (x >= c)
    {
        res += d;
    }
    cout << res << endl;
    return 0;
}