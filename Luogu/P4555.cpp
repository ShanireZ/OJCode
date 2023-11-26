#include <algorithm>
#include <iostream>
using namespace std;
char c, s[200005];
int p[200005], l[200005], r[200005], mx, mid, pos, ans = 2;
int main()
{
    s[++pos] = '#', c = getchar();
    while (c >= 'a' && c <= 'z')
    {
        s[++pos] = c, s[++pos] = '#', c = getchar();
    }
    for (int i = 1; i <= pos; i++)
    {
        p[i] = (i < mx ? min(p[2 * mid - i], mx - i) : 1);
        while (i - p[i] >= 1 && i + p[i] <= pos && s[i - p[i]] == s[i + p[i]])
        {
            p[i]++;
        }
        if (i + p[i] > mx)
        {
            mx = i + p[i], mid = i;
        }
        // 以每个点为中心的最长回文串长度
        l[i - p[i] + 1] = max(l[i - p[i] + 1], p[i] * 2 - 1);
        r[i + p[i] - 1] = max(r[i + p[i] - 1], p[i] * 2 - 1);
    }
    for (int i = 3; i <= pos; i += 2)
    {
        l[i] = max(l[i], l[i - 2] - 4);
    }
    for (int i = pos - 2; i >= 1; i -= 2)
    {
        r[i] = max(r[i], r[i + 2] - 4);
    }
    for (int i = 3; i <= pos - 2; i += 2)
    {
        ans = max(ans, l[i] / 2 + r[i] / 2);
    }
    cout << ans << endl;
    return 0;
}
// TAG: manacher 最长回文子串 双回文串