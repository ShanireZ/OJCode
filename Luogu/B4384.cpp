#include <algorithm>
#include <iostream>
using namespace std;
int T, n, ans, c;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> c;
            if (i == 1)
            {
                ans += c;
                continue;
            }
            for (int j = 1; j <= c; j++)
            {
                ans += (j == 1 || j == c || i * j % 10 == 6);
            }
        }
        cout << ans << endl;
    }
    return 0;
}