#include <algorithm>
#include <iostream>
using namespace std;
long long T, a, b, c, d;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> a >> b >> c >> d;
        if (c < a || d < b)
        {
            cout << -1 << endl;
            continue;
        }
        long long res = 0, t = 1;
        while ((c != a || d != b) && t)
        {
            if (c < d)
            {
                swap(a, b);
                swap(c, d);
            }
            t = (c - a) / d;
            res += t, c -= t * d;
        }
        cout << ((c != a || d != b) ? -1 : res) << endl;
    }
    return 0;
}