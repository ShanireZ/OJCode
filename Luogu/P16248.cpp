#include <algorithm>
#include <iostream>
using namespace std;
string s;
int ans, p;
int main()
{
    cin >> s;
    p = s.find("2026");
    while (p != string::npos)
    {
        ans++, s[p] = 'x';
        p = s.find("2026", p + 1);
    }
    p = s.find("202202");
    while (p != string::npos)
    {
        ans++, s[p] = 'x', s[p + 5] = 'x';
        p = s.find("202202", p + 1);
    }
    cout << ans << endl;
    return 0;
}