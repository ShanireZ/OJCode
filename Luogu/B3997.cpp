#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int main()
{
    cin >> s;
    int now = 0, sz = s.size(), ans = 0;
    for (int k = 1; k <= 1500 && now < sz; k++)
    {
        t = s.substr(now, min(k, sz - now));
        int ok = 1, len = t.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (t[i] != t[len - 1 - i])
            {
                ok = 0;
                break;
            }
        }
        ans += ok, now += k;
    }
    cout << ans << endl;
    return 0;
}