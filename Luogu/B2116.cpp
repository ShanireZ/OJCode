#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    cin >> s;
    for (int i = 0; i <= s.size() - 1; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + 32;
        }
        else
        {
            s[i] = s[i] - 32;
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i <= s.size() - 1; i++)
    {
        if ((s[i] >= 'A' && s[i] <= 'W') ||
            (s[i] >= 'a' && s[i] <= 'w'))
        {
            s[i] = s[i] + 3;
        }
        else
        {
            s[i] = s[i] - 23;
        }
    }
    cout << s << endl;
    return 0;
}