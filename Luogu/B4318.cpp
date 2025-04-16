#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    cin >> s;
    int cnt = 0, tot = 0, now = 0, trig = 0;
    for (char ch : s)
    {
        if (ch >= '0' && ch <= '9')
        {
            trig = 1, now = now * 10 + (ch - '0');
        }
        else
        {
            if (trig)
            {
                cnt++, tot += now;
                now = trig = 0;
            }
            if (ch == '.' || ch == '!' || ch == '?')
            {
                cout << cnt << " " << (tot % 2 ? "Odd" : "Even") << endl;
                cnt = tot = 0;
            }
        }
    }
    return 0;
}