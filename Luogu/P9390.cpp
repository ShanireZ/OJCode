#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long y, z;
    cin >> y >> z;
    long long z1 = z / 1000000, z2 = z % 1000000;
    long long x = max(100000ll, z1);
    if (y - z2 < 0 && x == z1)
    {
        x++;
    }
    long long c1 = abs(x * 1000000 + y - z);
    x = max(100000ll, z1);
    if (z2 - y < 0 && x == z1)
    {
        x--;
    }
    long long c2 = abs(z - (x * 1000000 + y));
    cout << min(c1, c2) << "\n";
    return 0;
}