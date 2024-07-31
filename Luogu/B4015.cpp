#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long long ans = 0, a;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a;
            if (i % 3 == 2 && j % 3 == 2)
            {
                ans += a;
            }
        }
    }
    cout << ans << endl;
    return 0;
}