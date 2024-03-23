#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int ans1 = 0, ans2 = 0, n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            cin >> x;
            if (i == m)
            {
                ans1 += x;
            }
            if (j == m)
            {
                ans2 += x;
            }
        }
    }
    cout << ans1 << " " << ans2 << " " << ans1 + ans2 << endl;
    return 0;
}