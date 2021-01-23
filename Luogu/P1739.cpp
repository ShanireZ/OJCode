#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
stack<char> stk;
int main()
{
    char ch = 'x';
    while (ch != '@')
    {
        if (ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            if (stk.size() > 0)
            {
                stk.pop();
            }
            else
            {
                cout << "NO";
                return 0;
            }
        }
        cin >> ch;
    }
    if (stk.size() == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}