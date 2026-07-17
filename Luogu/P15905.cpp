#include <algorithm>
#include <iostream>
using namespace std;
long long n, mx, ans, cnt, f, x[100005];
string s;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s >> f;
        if (s == "pig")
        {
            mx = max(mx, f);
        }
        else
        {
            x[++cnt] = f;
        }
    }
    ans = mx;
    for (int i = 1; i <= cnt; i++)
    {
        if (x[i] < mx)
        {
            ans += x[i];
        }
    }
    cout << ans << endl;
    return 0;
}