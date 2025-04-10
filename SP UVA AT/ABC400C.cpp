#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long n, res = 0;
    cin >> n;
    for (long long ap = 2; ap <= n; ap *= 2)
    {
        long long l = 1, r = sqrt(n); // 卡精度
        while (l <= r)
        {
            __int128 m = (l + r) / 2;
            (m * m * ap <= n) ? l = m + 1 : r = m - 1;
        }
        res += (r + 1) / 2;
    }
    cout << res << endl;
    return 0;
}