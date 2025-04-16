#include <algorithm>
#include <iostream>
using namespace std;
string s;
int main()
{
    int n, k, cq = 0, co = 0, trig = 0;
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?' && ((i >= 1 && s[i - 1] == 'o') || (i <= n - 2 && s[i + 1] == 'o')))
        {
            s[i] = '.';
        }
        if (s[i] == '?' && trig == 0)
        {
            cq++, trig = 1;
        }
        else if ((s[i] == '?' && trig) || s[i] != '?')
        {
            trig = 0;
        }
        co += (s[i] == 'o');
    }
    if (cq + co == k)
    {
        for (int i = 0, len = 0; i < n; i++)
        {
            len += (s[i] == '?');
            if (len % 2 == 1 && (s[i] != '?' || i == n - 1))
            {
                for (int j = 1, ex = (i == n - 1); j <= len; j++)
                {
                    s[i - j + ex] = (j % 2 ? 'o' : '.');
                }
            }
            if (s[i] != '?')
            {
                len = 0;
            }
        }
    }
    else if (co == k)
    {
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                s[i] = '.';
            }
        }
    }
    cout << s << endl;
    return 0;
}