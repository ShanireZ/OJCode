#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 2e9, pre;
    cin >> n >> pre;
    for (int i = 2; i <= n; i++)
    {
        int now;
        cin >> now;
        ans = min(ans, abs(now - pre));
        pre = now;
    }
    cout << ans << endl;
    return 0;
}