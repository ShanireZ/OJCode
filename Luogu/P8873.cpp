#include <iostream>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        long long k;
        cin >> k;
        __int128 l = 0, r = 2e9;
        while (l <= r)
        {
            __int128 mid = (l + r) / 2;
            if (2 * mid * mid + 3 * mid + 1 > k)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        __int128 pos = 2 * r * r + 3 * r + 1, base = r + 1, ans = 0;
        if (pos == k)
        {
            ans = 0;
        }
        else if (pos + base + 1 >= k)
        {
            ans = k - pos - 1;
        }
        else if (pos + base * 2 + 1 >= k)
        {
            ans = pos + base * 2 + 1 - k;
        }
        else if (pos + base * 3 + 1 >= k)
        {
            ans = k - pos - base * 2 - 1;
            if (ans != 0)
            {
                cout << '-';
            }
        }
        else
        {
            ans = pos + base * 4 + 1 - k;
            if (ans != 0)
            {
                cout << '-';
            }
        }
        if (ans == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            string opt;
            while (ans)
            {
                opt.insert(0, 1, ans % 10 + '0');
                ans /= 10;
            }
            cout << opt << endl;
        }
    }
    return 0;
}