#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, a, mn = 2e9, ans = -2e9;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        ans = max(ans, a - mn);
        mn = min(mn, a);
    }
    cout << ans << endl;
    return 0;
}