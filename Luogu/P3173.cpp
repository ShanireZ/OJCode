#include <algorithm>
#include <iostream>
using namespace std;
int n, m, h[10005], s[10005];
int main()
{
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        cin >> h[i];
    }
    for (int i = 1; i < m; i++)
    {
        cin >> s[i];
    }
    sort(h + 1, h + n, greater<int>()), sort(s + 1, s + m, greater<int>());
    long long ans = 0, ph = 1, ps = 1;
    while (ph < n || ps < m)
    {
        if (ps == m || (ph < n && h[ph] > s[ps]))
        {
            ans += h[ph++] * ps;
        }
        else
        {
            ans += s[ps++] * ph;
        }
    }
    cout << ans << endl;
    return 0;
}