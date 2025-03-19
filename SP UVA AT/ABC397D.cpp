#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
void qwrite(__int128 x)
{
    string s;
    while (x)
    {
        s.insert(s.begin(), x % 10 + '0');
        x /= 10;
    }
    cout << s;
}
int main()
{
    long long n;
    cin >> n;
    long long tp = pow(n, 1.0 / 3);
    for (__int128 k = 1; k <= tp; k++) // k = x - y
    {
        // 3kyy + 3kky + kkk - n = 0
        __int128 y = (-3 * k * k + pow(9 * k * k * k * k - 12 * k * (k * k * k - n), 0.5)) / 6 / k;
        __int128 x = k + y;
        if (y && x * x * x - y * y * y == n)
        {
            qwrite(x);
            cout << " ";
            qwrite(y);
            cout << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}