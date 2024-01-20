#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, op;
long long n, sz, pos, ex, f = 1;
int main()
{
    cin >> s >> n;
    sz = s.size();
    for (int i = 1; i <= n; i++)
    {
        cin >> op;
        if (op == "rev")
        {
            pos = (pos - f + sz) % sz;
            f = -f;
        }
        else
        {
            cin >> ex;
            ex %= sz;
            (op == ">") ? (pos -= ex * f) : (pos += ex * f);
            pos = (pos + sz) % sz;
        }
    }
    for (int c = 1; c <= sz; c++)
    {
        cout << s[pos];
        pos = (pos + f + sz) % sz;
    }
    return 0;
}