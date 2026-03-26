#include <algorithm>
#include <iostream>
using namespace std;
long long T, n, mod = 1e9, p[1000005];
int main()
{
    cin >> T;
    p[0] = 1;
    for (int i = 1; i <= 1000000; i++)
    {
        p[i] = p[i - 1] * 3 % mod;
    }
    while (T--)
    {
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        long long cnt = n / 3;
        if (n % 3 == 0)
        {
            cout << p[cnt] << endl;
        }
        else if (n % 3 == 2)
        {
            cout << p[cnt] * 2 % mod << endl;
        }
        else
        {
            cout << p[cnt - 1] * 4 % mod << endl;
        }
    }
    return 0;
}