#include <algorithm>
#include <iostream>
using namespace std;
int a[5], b[5];
string s[5] = {"", "yesterday", "today", "tomorrow"};
string xq[10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int main()
{
    cin >> a[1] >> a[2] >> a[3] >> b[1] >> b[2] >> b[3];
    for (int i = 1; i <= 3; i++)
    {
        int now = a[i];
        if (i == 1)
        {
            now = (now == 6 ? 0 : now + 1);
        }
        else if (i == 3)
        {
            now = (now == 0 ? 6 : now - 1);
        }
        int yet = (now == 0 ? 6 : now - 1), tom = (now == 6 ? 0 : now + 1);
        int c1 = (yet == a[1]) + (now == a[2]) + (tom == a[3]), c2 = (yet == b[1]) + (now == b[2]) + (tom == b[3]);
        if (c1 == c2 && c1 == 1)
        {
            cout << xq[now] << "\n";
            if (a[1] == yet)
            {
                cout << s[1] << "\n";
            }
            else if (a[2] == now)
            {
                cout << s[2] << "\n";
            }
            else
            {
                cout << s[3] << "\n";
            }
            if (b[1] == yet)
            {
                cout << s[1] << "\n";
            }
            else if (b[2] == now)
            {
                cout << s[2] << "\n";
            }
            else
            {
                cout << s[3] << "\n";
            }
        }
    }
    return 0;
}