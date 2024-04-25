#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int c[105];
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        memset(c, 0, sizeof(c));
        int n, x, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            c[x]++;
        }
        for (int i = 1; i <= 100; i++)
        {
            ans += c[i] / 3;
        }
        cout << ans << "\n";
    }
    return 0;
}