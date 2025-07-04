#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long ans = 0, n, pre = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long now;
        cin >> now;
        now = max(now, pre + 1);
        ans += now, pre = now;
    }
    cout << ans << endl;
    return 0;
}