#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    c = c - 2 * b, d = d - 2 * a - 4 * b;
    if (c == 0 && d == 0)
    {
        cout << -1 << endl;
        cout << -1 << endl;
        return 0;
    }
    if (c < 0 || d < -2)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << c << " " << d + 2 << endl;
    }
    if (c < -2 || d < -4)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << c + 2 << " " << d + 4 << endl;
    }
    return 0;
}