#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int a[30005] = {0, 1}, pos = 1, p1 = 1, p2 = 1;
string s = "1";
int main()
{
    int k, m;
    cin >> k >> m;
    for (int i = 2; i <= k; i++)
    {
        if (p1 <= pos && a[p1] * 2 + 1 <= a[p2] * 4 + 5)
        {
            a[++pos] = a[p1] * 2 + 1;
            p1++;
        }
        else
        {
            a[++pos] = a[p2] * 4 + 5;
            p2++;
        }
        s += to_string(a[pos]);
    }
    cout << s << endl;
    int p = 1;
    while (m)
    {
        if (s[p] > s[p - 1])
        {
            s.erase(p - 1, 1);
            m--, p = (p == 1 ? 1 : p - 1);
        }
        else
        {
            p++;
        }
    }
    cout << s << endl;
    return 0;
}