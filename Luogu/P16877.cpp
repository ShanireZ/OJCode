#include <algorithm>
#include <iostream>
using namespace std;
int T, n;
string s;
int main()
{
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n >> s;
        int ok = 0;
        for (char ch : s)
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ok = 1;
                break;
            }
        }
        if (ok == 0)
        {
            s.append("A");
        }
        ok = 0;
        for (char ch : s)
        {
            if (ch >= 'a' && ch <= 'z')
            {
                ok = 1;
                break;
            }
        }
        if (ok == 0)
        {
            s.append("a");
        }
        ok = 0;
        for (char ch : s)
        {
            if (ch >= '0' && ch <= '9')
            {
                ok = 1;
                break;
            }
        }
        if (ok == 0)
        {
            s.append("0");
        }
        ok = 0;
        for (char ch : s)
        {
            if (ch == '#' || ch == '@' || ch == '*' || ch == '&')
            {
                ok = 1;
                break;
            }
        }
        if (ok == 0)
        {
            s.append("#");
        }
        while (s.size() < 7)
        {
            s.append("A");
        }
        cout << "Case #" << t << ": " << s << endl;
    }
    return 0;
}