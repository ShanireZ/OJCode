#include <algorithm>
#include <iostream>
using namespace std;
string s, now;
int t, op;
int main()
{
    getline(cin, s);
    cout << '*';
    for (char ch : s)
    {
        if (ch == '(')
        {
            op = 1;
        }
        else if (ch == ')')
        {
            op = 2;
        }
        else if (ch == '[')
        {
            continue;
        }
        else if (ch == ']')
        {
            while (t)
            {
                cout << now;
                t--;
            }
            now.clear();
        }
        else
        {
            if (op == 1)
            {
                now += ch;
            }
            else
            {
                t = t * 10 + (ch - '0');
            }
        }
    }
    cout << '*';
    return 0;
}