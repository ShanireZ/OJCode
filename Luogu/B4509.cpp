#include <algorithm>
#include <iostream>
using namespace std;
string s, t;
int main()
{
    cin >> s;
    if (s[0] >= 'a' && s[0] <= 'z')
    {
        t += s[0] - ('a' - 'A');
    }
    else
    {
        t += s[0];
    }
    for (int i = 1; i < (int)s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z' && s[i - 1] != '.')
        {
            t += '.';
            t += s[i];
        }
        else if (s[i - 1] == '.' && s[i] >= 'a' && s[i] <= 'z')
        {
            t += s[i] - ('a' - 'A');
        }
        else
        {
            t += s[i];
        }
    }
    if (t.back() != '.')
    {
        t += '.';
    }
    cout << t << endl;
    return 0;
}