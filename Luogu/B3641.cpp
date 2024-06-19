#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int a1, b1, c1, a2, b2, c2, x, y;
void check(string s, int op)
{
    int now = 0, p = 0, f = 1;
    while (s[p] == '-' || isdigit(s[p]))
    {
        if (s[p] == '-')
        {
            f = -1;
        }
        else
        {
            now = now * 10 + s[p] - '0';
        }
        p++;
    }
    now = max(1, now);
    op == 1 ? a1 = f *now : a2 = f * now;
    p++, f = 1, now = 0;
    while (s[p] == '-' || s[p] == '+' || isdigit(s[p]))
    {
        if (s[p] == '-')
        {
            f = -1;
        }
        else if (isdigit(s[p]))
        {
            now = now * 10 + s[p] - '0';
        }
        p++;
    }
    now = max(1, now);
    op == 1 ? b1 = f *now : b2 = f * now;
    p += 2, f = 1, now = 0;
    while (p < s.size())
    {
        if (s[p] == '-')
        {
            f = -1;
        }
        else
        {
            now = now * 10 + s[p] - '0';
        }
        p++;
    }
    op == 1 ? c1 = f *now : c2 = f * now;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    check(s1, 1), check(s2, 2);
    int g = __gcd(abs(a1), abs(a2));
    int x1 = a2 / g, x2 = a1 / g;
    a1 = a1 * x1, a2 = a2 * x2;
    b1 = b1 * x1, b2 = b2 * x2;
    c1 = c1 * x1, c2 = c2 * x2;
    y = (c2 - c1) / (b2 - b1);
    x = (c1 - b1 * y) / a1;
    cout << x << endl;
    cout << y << endl;
    return 0;
}