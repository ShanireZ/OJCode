#include <algorithm>
#include <iostream>
using namespace std;
char s[22000005], ch;
int p[22000005], pos, ans = 1, mid = 1, mx = 2;
int main()
{
    s[++pos] = '#', ch = getchar();
    while (ch >= 'a' && ch <= 'z')
    {
        s[++pos] = ch, s[++pos] = '#', ch = getchar();
    }
    for (int i = 1; i <= pos; i++)
    {
        p[i] = (i < mx ? min(mx - i, p[2 * mid - i]) : 1);
        while (i + p[i] <= pos && i - p[i] >= 1 && s[i + p[i]] == s[i - p[i]])
        {
            p[i]++;
        }
        if (mx < i + p[i])
        {
            mid = i, mx = i + p[i];
        }
        ans = max(ans, p[i] - 1);
    }
    cout << ans << endl;
    return 0;
}
// TAG: manacher 最长回文子串