#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    char c;
    cin >> a >> b >> c;
    if (c == '+')
    {
        cout << a + b << endl;
    }
    else if (c == '-')
    {
        cout << a - b << endl;
    }
    else if (c == '*')
    {
        cout << a * b << endl;
    }
    else if (c == '/')
    {
        if (b == 0)
        {
            cout << "Divided by zero!\n";
        }
        else
        {
            cout << a / b << endl;
        }
    }
    else
    {
        cout << "Invalid operator!\n";
    }
    return 0;
}