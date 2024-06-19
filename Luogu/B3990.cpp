#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s, t;
int main()
{
    cin >> s >> t;
    int n = s.size(), m = t.size();
    for (int i = 0; i + m <= n; i++)
    {
        bool trig = 1;
        for (int j = 0; j < m; j++)
        {
            if (s[i + j] == t[j] || s[i + j] == '?' || t[j] == '?')
            {
                continue;
            }
            else
            {
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            cout << i + 1 << " " << i + m << endl;
        }
    }
    return 0;
}