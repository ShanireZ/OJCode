#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, m;
    cin >> n >> m;
    if (n == 1)
    {
        cout << m + 1 << endl;
        return 0;
    }
    __int128 res = 1, base = n;
    for (int i = 1; i <= m; i++)
    {
        res = res + base;
        base = base * n;
        if (res > 1e9)
        {
            cout << "inf" << endl;
            return 0;
        }
    }
    int ans = res;
    cout << ans << endl;
    return 0;
}