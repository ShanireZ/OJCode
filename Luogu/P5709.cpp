#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int m, t, s;
    cin >> m >> t >> s;
    if (m - ceil(1.0 * s / t) >= 0)
    {
        cout << m - ceil(1.0 * s / t);
    }
    else
    {
        cout << 0;
    }
    return 0;
}