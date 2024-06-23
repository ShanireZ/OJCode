#include <algorithm>
#include <iostream>
using namespace std;
string s, t, now;
int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> s >> t;
        int ans = 0, slen = s.size(), tlen = t.size();
        for (int l = 1, r = tlen - l; l < tlen && l < slen && r < slen; l++, r--)
        {
            now = s.substr(slen - r, r) + s.substr(0, l);
            if (now == t)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}