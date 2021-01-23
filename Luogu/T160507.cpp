#include <iostream>
using namespace std;
int main()
{
    int n, v, m, a;
    cin >> n >> v >> m >> a;
    long long ans = 0;
    while (n > 0)
    {
        ans += v * min(m, n);
        n -= m;
        v += a;
    }
    cout << ans;
    return 0;
}