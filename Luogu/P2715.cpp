#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
string s, t;
int trans(char c)
{
    if (c == '+')
    {
        return 1;
    }
    else if (c == '-')
    {
        return 2;
    }
    else if (c == '*')
    {
        return 3;
    }
    else
    {
        return 4;
    }
}
int main()
{
    while (cin >> s)
    {
        t += s;
    }
    t.erase(remove(t.begin(), t.end(), ' '), t.end());
    int p1 = t.find_first_of("+-*/"), p2 = t.find("=");
    int op = trans(t[p1]);
    double a = t[0] == '?' ? -1 : stoi(t.substr(0, p1));
    double b = t[p1 + 1] == '?' ? -1 : stoi(t.substr(p1 + 1, p2 - p1 - 1));
    double c = t[p2 + 1] == '?' ? -1 : stoi(t.substr(p2 + 1));
    if (a == -1)
    {
        if (op == 1)
        {
            a = c - b;
        }
        else if (op == 2)
        {
            a = c + b;
        }
        else if (op == 3)
        {
            a = c / b;
        }
        else
        {
            a = c * b;
        }
        cout << fixed << setprecision(2) << a << endl;
    }
    else if (c == -1)
    {
        if (op == 1)
        {
            c = a + b;
        }
        else if (op == 2)
        {
            c = a - b;
        }
        else if (op == 3)
        {
            c = a * b;
        }
        else if (op == 4)
        {
            c = a / b;
        }
        cout << fixed << setprecision(2) << c << endl;
    }
    else
    {
        if (op == 1)
        {
            b = c - a;
        }
        else if (op == 2)
        {
            b = a - c;
        }
        else if (op == 3)
        {
            b = c / a;
        }
        else
        {
            b = a / c;
        }
        cout << fixed << setprecision(2) << b << endl;
    }
    return 0;
}