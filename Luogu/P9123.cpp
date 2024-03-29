#include <algorithm>
#include <iostream>
using namespace std;
long long d[100005];
int main()
{
    long long n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    long long ans = k + 1, now = d[1];
    for (int i = 2; i <= n; i++)
    {
        ans += (d[i] - now < k + 1 ? d[i] - now : k + 1);
        now = d[i];
    }
    cout << ans << "\n";
    return 0;
}
// TAG:模拟 贪心 USACO 23FEB Bronze