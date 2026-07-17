#include <algorithm>
#include <iostream>
using namespace std;
int T;
string s, t;
int main()
{
    cin >> T;
    for (int id = 1; id <= T; id++)
    {
        int cnt = 0, now = 0, trig = 1;
        cin >> s >> t;
        for (int i = 0; i < (int)s.size(); i++, now++)
        {
            while (now < (int)t.size() && s[i] != t[now])
            {
                now++, cnt++;
            }
            if (now == (int)t.size())
            {
                trig = 0;
                break;
            }
        }
        cout << "Case #" << id << ": ";
        if (trig)
        {
            cout << cnt + t.size() - now << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}