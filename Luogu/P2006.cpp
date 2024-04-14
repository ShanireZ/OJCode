#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long k, m, n, ok = 1;
    cin >> k >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        long long a, b;
        cin >> a >> b;
        if (a == 0 || k / a * b >= n)
        {
            cout << i << " ";
            ok = 0;
        }
    }
    if (ok)
    {
        cout << -1 << endl;
    }
    return 0;
}