#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ans = 0;
    cin >> n;
    for (int i = 1, t = n; i <= n; i++, t--)
    {
        ans += i * t;
    }
    cout << ans << endl;
    return 0;
}
// TAG: 模拟 GESP1