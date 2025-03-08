#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    int t1 = h1 * 3600 + m1 * 60 + s1, t2 = h2 * 3600 + m2 * 60 + s2;
    if (t1 < t2)
    {
        t1 += 86400;
    }
    t1 -= t2;
    cout << t1 / 3600 << ' ' << t1 % 3600 / 60 << ' ' << t1 % 60 << endl;
    return 0;
}