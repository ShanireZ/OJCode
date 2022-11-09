#include <iostream>
using namespace std;
int a[105];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                for (int k = j; k <= n; k++)
                {
                    if (a[i] + a[j] == a[k])
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}