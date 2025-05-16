#include <algorithm>
#include <iostream>
using namespace std;
long long n, p, inv[3000005];
int main()
{
    cin >> n >> p;
    inv[0] = inv[1] = 1;
    cout << "1\n";
    for (int i = 2; i <= n; i++)
    {
        inv[i] = (p - p / i) * inv[p % i] % p;
        cout << inv[i] << "\n";
    }
    return 0;
}