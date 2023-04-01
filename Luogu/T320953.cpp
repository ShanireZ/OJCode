#include <algorithm>
#include <iostream>
using namespace std;
int t[1000005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        t[a]++, t[b + 1]--;
    }
    int ans = t[0];
    for (int i = 1; i <= 1000000; i++)
    {
        t[i] += t[i - 1];
        ans = max(ans, t[i]);
    }
    cout << ans << "\n";
    return 0;
}
// TAG: 一维差分