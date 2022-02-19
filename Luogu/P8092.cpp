#include <iostream>
using namespace std;
long long h[100005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> h[i];
        }
        long long ans = 0;
        while (ans != -1)
        {
            int ok = 1;
            for (int i = 1; i <= n - 2; i++)
            {
                if (h[i] < 0)
                {
                    ans = -1;
                    break;
                }
                if (h[i] < h[i + 1])
                {
                    ok = 0;
                    int x = h[i + 1] - h[i];
                    h[i + 1] -= x, h[i + 2] -= x;
                    ans += x;
                }
            }
            if (ans == -1)
            {
                break;
            }
            for (int i = n; i >= 3; i--)
            {
                if (h[i] < 0)
                {
                    ans = -1;
                    break;
                }
                if (h[i] < h[i - 1])
                {
                    ok = 0;
                    int x = h[i - 1] - h[i];
                    h[i - 1] -= x, h[i - 2] -= x;
                    ans += x;
                }
            }
            if (ok == 1)
            {
                break;
            }
        }
        for (int i = 1; i < n; i++)
        {
            if (h[i] != h[i + 1])
            {
                ans = -1;
                break;
            }
        }
        if (ans >= 0)
        {
            cout << ans * 2 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}