#include <algorithm>
#include <iostream>
using namespace std;
int T;
string s, str;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;
        int res = 0;
        for (int len = 1; len <= s.size(); len++)
        {
            for (int st = 0; st + len - 1 < s.size(); st++)
            {
                str = s.substr(st, len);
                int ok = 1;
                for (int i = 0, j = str.size() - 1; i < str.size() / 2; i++, j--)
                {
                    if ((str[i] == str[j]) || (str[i] == '?') || (str[j] == '?'))
                    {
                        continue;
                    }
                    ok = 0;
                    break;
                }
                res += ok;
            }
        }
        cout << res << endl;
    }
    return 0;
}