#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
bool check(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
bool checkwithn(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'n';
}
string xy[15], s;
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> xy[i];
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> s;
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            int p = s.find(xy[j]);
            while (p != string::npos)
            {
                if (p == 0 || (check(s[p]) && check(s[p - 1])) || (!check(s[p]) && checkwithn(s[p - 1])))
                {
                    int pp = p + xy[j].size() - 1;
                    if (s[pp] != 'n' || pp == s.size() - 1 || !check(s[pp + 1]))
                    {
                        cnt++;
                        break;
                    }
                }
                p = s.find(xy[j], p + 1);
            }
        }
        cout << (cnt == 1 ? "Yes, Commander" : "No, Commander") << "\n";
    }
    return 0;
}