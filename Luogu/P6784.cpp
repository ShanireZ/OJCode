#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    if (a < b)
    {
        swap(a, b);
    }
    long long d = a - b, x = b;
    if (c > d)
    {
        x += d + (c - d) / 2;
    }
    else
    {
        x += c;
    }
    long long ans = (sqrt(8 * x + 1.0) - 1) / 2;
    cout << ans << endl;
    return 0;
}