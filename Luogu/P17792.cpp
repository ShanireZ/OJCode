#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int l, r, cnt = 0;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        int x = i, ok = 1, pos = 0, a[10] = {0};
        while (x)
        {
            a[++pos] = x % 10;
            x /= 10;
        }
        reverse(a + 1, a + pos + 1);
        for (int j = 1; j <= pos; j += 2)
        {
            if (a[j] % 2 != 1 || a[j + 1] % 2 != 0)
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << i << " ";
            cnt++;
        }
    }
    if (cnt == 0)
    {
        cout << -1 << endl;
    }
    return 0;
}