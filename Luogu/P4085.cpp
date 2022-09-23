#include <cmath>
#include <iostream>
using namespace std;
int n, f[100005], s[100005], st[100005][20];
long long m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> f[i] >> s[i];
        st[i][0] = s[i];
    }
    int len = 1, half = 1;
    for (int x = 1; x <= int(log2(n)); x++)
    {
        len *= 2;
        for (int i = 1; i + len - 1 <= n; i++)
        {
            st[i][x] = max(st[i][x - 1], st[i + half][x - 1]);
        }
        half *= 2;
    }
    int l = 1, r = 1, ans = 0x3f3f3f3f;
    long long now = 0;
    while (r <= n)
    {
        now = now + f[r];
        if (now >= m)
        {
            int x = log2(r - l + 1);
            int half = pow(2, x);
            ans = min(ans, max(st[l][x], st[r - half + 1][x]));
            now = now - f[l];
            l++;
        }
        r++;
    }
    cout << ans << endl;
    return 0;
}