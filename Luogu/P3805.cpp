#include <algorithm>
#include <iostream>
using namespace std;
int p[22000005], mid, mx, ans, pos = 1;
char s[22000005], c;
int main()
{
    cin.tie(0)->ios::sync_with_stdio(false);
    s[1] = '#';
    while (cin >> c)
    {
        s[++pos] = c;
        s[++pos] = '#';
    }
    for (int i = 1; i <= pos; i++)
    {
        p[i] = (i < mx ? min(mx - i, p[mid * 2 - i]) : 1);
        while (i - p[i] >= 1 && i + p[i] <= pos && s[i + p[i]] == s[i - p[i]])
        {
            p[i]++;
        }
        if (mx < i + p[i])
        {
            mx = i + p[i], mid = i;
        }
        ans = max(ans, p[i] - 1);
    }
    cout << ans << endl;
    return 0;
}
// TAG: Manacher