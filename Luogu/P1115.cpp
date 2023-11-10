#include <iostream>
using namespace std;
int main()
{
    int n, ans = -(2e9 + 10), pre = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int now;
        cin >> now;
        now += pre;
        ans = max(ans, now), pre = max(now, 0);
    }
    cout << ans << endl;
    return 0;
}