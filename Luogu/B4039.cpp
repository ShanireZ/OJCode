#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
string s;
int n, l[105], r[105];
bool check(int x, int y)
{
    while (x < y)
    {
        if (s[x] != s[y])
        {
            return false;
        }
        x++, y--;
    }
    return true;
}
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s;
        memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r));
        for (int i = 0; i < (int)s.size(); i++)
        {
            l[i] = check(0, i), r[i] = check(i, (int)s.size() - 1);
        }
        int ok = 0;
        for (int i = 1; i < (int)s.size() - 2 && !ok; i++)
        {
            ok = (l[i] && r[i + 1]);
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}