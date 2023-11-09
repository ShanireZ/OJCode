#include <iostream>
using namespace std;
long long f[100005], ans, n, m;
int main()
{
    cin >> n >> m;
    for (int i = min(n, m); i >= 1; i--)
    {
        f[i] = (n / i) * (m / i);
        for (int j = i + i; j <= min(n, m); j += i)
        {
            f[i] -= f[j];
        }
        ans += f[i] * i;
    }
    cout << ans * 2 - n * m << endl;
    return 0;
}