#include <algorithm>
#include <iostream>
using namespace std;
long long n, m, cnt[1000005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt[(a + b) % n]++;
    }
    long long ans = m * (m - 1) / 2;
    for (int i = 0; i < n; i++)
    {
        ans -= cnt[i] * (cnt[i] - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}