#include <algorithm>
#include <iostream>
using namespace std;
string s, ss;
int q, n, v[30];
int main()
{
    cin >> q;
    while (q--)
    {
        fill(v, v + 30, 0);
        cin >> n >> s;
        for (int i = 1; i <= n; i++)
        {
            cin >> ss;
            v[ss[0] - 'a'] = stoll(ss.substr(2));
        }
        int l = 0, r = 0, pos = 0, f = 1, now = 0;
        while (s[pos] != '=')
        {
            if (s[pos] == '+' || s[pos] == '-')
            {
                f = (s[pos] == '+' ? 1 : -1);
                pos++;
            }
            now = 0;
            if (s[pos] >= 'a' && s[pos] <= 'z')
            {
                now = v[s[pos] - 'a'];
                pos++;
            }
            while (s[pos] >= '0' && s[pos] <= '9')
            {
                now = now * 10 + s[pos] - '0';
                pos++;
            }
            l += f * now;
        }
        pos++, f = 1;
        while (pos < (int)s.size())
        {
            if (s[pos] == '+' || s[pos] == '-')
            {
                f = (s[pos] == '+' ? 1 : -1);
                pos++;
            }
            now = 0;
            if (s[pos] >= 'a' && s[pos] <= 'z')
            {
                now = v[s[pos] - 'a'];
                pos++;
            }
            while (s[pos] >= '0' && s[pos] <= '9')
            {
                now = now * 10 + s[pos] - '0';
                pos++;
            }
            r += f * now;
        }
        cout << (l == r ? "Yes" : "No") << endl;
    }
    return 0;
}