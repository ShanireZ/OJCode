#include <algorithm>
#include <iostream>
using namespace std;
int cnt[2005];
int main()
{
    int c, f1, f2, d;
    cin >> c >> f1 >> f2 >> d;
    for (int i = 1; i <= c; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l <= d)
        {
            cnt[l]++;
        }
        if (r + 1 <= d)
        {
            cnt[r + 1]--;
        }
    }
    for (int i = 1; i <= d; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    int res = f1 - f2;
    for (int i = d; i >= 1; i--)
    {
        res -= cnt[i];
        if (res <= 0)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}