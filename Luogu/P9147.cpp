#include <iostream>
using namespace std;
struct Seg
{
    int l, r, len;
};
Seg s[1000005];
int a[1000005], n, pos;
int main()
{
    cin >> n;
    a[0] = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] <= a[s[pos].r])
        {
            s[++pos].l = i;
        }
        s[pos].r = i, s[pos].len++;
    }
    int ans = s[1].len;
    for (int i = 2; i <= n; i++)
    {
        if (s[i].len == 1 || s[i - 1].len == 1 || a[s[i].l + 1] - a[s[i - 1].r] > 1 || a[s[i].l] - a[s[i - 1].r - 1] > 1)
        {
            ans = max(ans, s[i].len + s[i - 1].len);
        }
        else
        {
            ans = max(ans, max(s[i].len, s[i - 1].len) + 1);
        }
    }
    cout << ans << "\n";
    return 0;
}