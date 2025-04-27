#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        if (m == 1 && n == 1)
        {
            cout << 0 << endl;
            continue;
        }
        if (m == 1 || (m % 2 == 1 && n % 2 == 0))
        {
            cout << -1 << endl;
            continue;
        }
        if (m % 2 == 0)
        {
            int l = 1, r = n;
            int cnt = (n % 2 == 0 ? (n + m - 1) / m : (n + m - 2) / m);
            cout << cnt << endl;
            while (cnt--)
            {
                for (int i = 1; i <= m / 2; i++)
                {
                    if (l == r || l - r == 1)
                    {
                        l = 1, r = n;
                    }
                    cout << l << " " << r << " ";
                    l++, r--;
                }
                cout << endl;
            }
        }
        else
        {
            int mid = n / 2 + 1, l = 1, r = n;
            int cnt = (n - 1 + m - 2) / (m - 1);
            cout << cnt << endl;
            while (cnt--)
            {
                for (int i = 1; i <= m / 2; i++)
                {
                    if (l == r)
                    {
                        l = 1, r = n;
                    }
                    cout << l << " " << r << " ";
                    l++, r--;
                }
                cout << mid << endl;
            }
        }
    }
    return 0;
}