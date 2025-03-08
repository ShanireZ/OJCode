#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m, a, ans = 0, s = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (s >= m)
        {
            ans += a + a, s /= 2;
        }
        else
        {
            ans += a / 2, s += a;
        }
    }
    cout << ans << endl;
    return 0;
}