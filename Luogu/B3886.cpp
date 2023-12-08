#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    int s = 5 * c;
    if (s > m)
    {
        s += d * 20;
    }
    s -= (b - d) * 20;
    cout << max(0, s) << endl;
    return 0;
}