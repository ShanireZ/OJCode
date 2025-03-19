#include <algorithm>
#include <iostream>
using namespace std;
string cd[205], s, now;
int n, l, r, pos;
int main()
{
    cin >> n >> s;
    for (char ch : s)
    {
        if (ch == ',')
        {
            cd[++pos] = now;
            now.clear();
        }
        else
        {
            now += ch;
        }
    }
    cd[++pos] = now;
    cin >> s;
    l = n, r = n + n;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        now = (s[i] == 'L' ? cd[l--] : cd[r--]);
        if (i % 2 == 1)
        {
            cout << now << endl;
        }
    }
    return 0;
}