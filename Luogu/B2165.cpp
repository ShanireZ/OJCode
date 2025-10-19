#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int T, ok;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;
        t.clear(), ok = 1;
        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                t += s[i];
            }
            else
            {
                if ((t.back() == '(' && s[i] == ')') ||
                    (t.back() == '[' && s[i] == ']') ||
                    (t.back() == '{' && s[i] == '}'))
                {
                    t.pop_back();
                }
                else
                {
                    ok = 0;
                    break;
                }
            }
        }
        cout << (ok && t.empty() ? "YES" : "NO") << endl;
    }
    return 0;
}