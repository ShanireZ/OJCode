#include <algorithm>
#include <iostream>
using namespace std;
string s, sl, sr;
int main()
{
    cin >> s;
    int ans = 0, l = 0, r = s.size() - 1;
    while (l <= r)
    {
        sl += s[l], sr = s[r] + sr;
        if (sl == sr)
        {
            ans += 1 + (l != r);
            sl.clear(), sr.clear();
        }
        l++, r--;
    }
    cout << (ans ? "YES" : "NO") << endl;
    if (ans)
    {
        cout << ans + (sl.size() != 0) << endl;
    }
    return 0;
}