#include <iostream>
using namespace std;
int a[100005];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, tot = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            tot += a[i];
        }
        for (int i = n; i >= 1; i--) //分为i个区域
        {
            if (tot % i != 0)
            {
                continue;
            }
            int bz = tot / i, now = 0, trig = 1;
            for (int j = 1; j <= n; j++)
            {
                now += a[j];
                if (now == bz)
                {
                    now = 0;
                }
                else if (now > bz)
                {
                    trig = 0;
                    break;
                }
            }
            if (trig)
            {
                cout << n - i << endl;
                break;
            }
        }
    }
    return 0;
}