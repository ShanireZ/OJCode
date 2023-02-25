#include <iostream>
#include <string>
using namespace std;
string s;
int main()
{
    cin >> s;
    char ch = '#';
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] > '9' || s[i] < '0')
        {
            if (ch != '#')
            {
                cout << ch;
            }
            ch = s[i];
            continue;
        }
        for (int j = 1; j <= s[i] - '0'; j++)
        {
            cout << ch;
        }
        ch = '#';
    }
    if (ch != '#')
    {
        cout << ch;
    }
    return 0;
}