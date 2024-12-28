#include <algorithm>
#include <iostream>
using namespace std;
long long p[100005], fx[100005], n, a, b, ans = 1e18;
int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; i++)
    {
        fx[i] = p[i] + fx[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        long long res = a * (i * p[i] - fx[i]) + b * (fx[n] - fx[i] - (n - i) * p[i]);
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}