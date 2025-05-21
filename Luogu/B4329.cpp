#include <algorithm>
#include <iostream>
using namespace std;
int d[5005], a[5005], n, ans = 1;
int main()
{
    cin >> n >> a[1];
    for (int i = 2, now = 0, len = -1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        if (d[i] == len)
        {
            now++;
        }
        else
        {
            ans = max(ans, now + 1);
            len = d[i], now = 1;
        }
    }
    cout << ans << endl;
    return 0;
}