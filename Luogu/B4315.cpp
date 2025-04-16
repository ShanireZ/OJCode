#include <algorithm>
#include <iostream>
using namespace std;
int t[55], s[55], n, x, y, ans;
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    cin >> x >> y;
    for (int i = x; i <= y; i++)
    {
        ans += t[i] + s[i];
    }
    cout << ans - t[x] << endl;
    return 0;
}