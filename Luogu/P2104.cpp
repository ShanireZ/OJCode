#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string s;
int main()
{
    int n, m;
    cin >> n >> m;
    cin >> s;
    for (int i = 1; i <= m; i++)
    {
        char ch;
        cin >> ch;
        if (ch == '*')
        {
            if (s != "0")
            {
                s.append("0");
            }
        }
        else if (ch == '/')
        {
            if (s != "0")
            {
                s.erase(s.size() - 1);
            }
        }
        else if (ch == '+')
        {
            for (int j = s.size() - 1; j >= 0; j--)
            {
                if (s[j] == '1')
                {
                    s[j] = '0';
                }
                else
                {
                    s[j] = '1';
                    break;
                }
            }
        }
        else if (ch == '-')
        {
            for (int j = s.size() - 1; j >= 0; j--)
            {
                if (s[j] == '0')
                {
                    s[j] = '1';
                }
                else
                {
                    s[j] = '0';
                    break;
                }
            }
        }
    }
    cout << s;
    return 0;
}