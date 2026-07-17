#include <algorithm>
#include <iostream>
using namespace std;
int n, a, ans = -1e6, pre = -1e6;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        pre = a + (pre > 0) * pre;
        ans = max(ans, pre);
    }
    cout << ans << endl;
    return 0;
}