#include <algorithm>
#include <iostream>
using namespace std;
int n, m, ans, a[200005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 29; i >= 0; i--)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            if (a[j] == -1 || (a[j] & (1 << i)) == 0)
            {
                continue;
            }
            cnt++;
        }
        if (cnt >= m)
        {
            ans |= (1 << i);
            for (int j = 1; j <= n; j++)
            {
                if (a[j] != -1 && (a[j] & (1 << i)) == 0)
                {
                    a[j] = -1;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}