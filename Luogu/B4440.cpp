#include <algorithm>
#include <iostream>
using namespace std;
int T, a, b, c;
int main()
{
    cin >> T;
    while (T--)
    {
        int res = 0;
        cin >> a >> b >> c;
        for (int y = 1; b * y < c; y++)
        {
            int x = a / (c - b * y);
            res += (x > 0 && a % x == 0 && a / x + b * y == c);
        }
        cout << res << endl;
    }
    return 0;
}