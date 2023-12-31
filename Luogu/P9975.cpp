#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
long long c[300005], n, pos, ans, cnt, d = 1e9;
int main()
{
    cin >> n >> s;
    s = "0" + s;
    int st = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '1' && s[i - 1] == '0')
        {
            cnt = 1;
            if (i != 1)
            {
                st = 0;
            }
        }
        else if (s[i] == '1' && s[i - 1] == '1')
        {
            cnt++;
        }
        else if (s[i] == '0' && s[i - 1] == '1')
        {
            c[++pos] = cnt;
            if (st == 1)
            {
                d = min(d, cnt - 1);
            }
            else
            {
                d = min(d, (cnt - 1) / 2);
            }
        }
    }
    if (s[n] == '1')
    {
        c[++pos] = cnt;
        d = min(d, cnt - 1);
    }
    for (int i = 1; i <= pos; i++)
    {
        ans += c[i] / (1 + d * 2) + bool(c[i] % (1 + d * 2));
    }
    cout << ans << endl;
    return 0;
}