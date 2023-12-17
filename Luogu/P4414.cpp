#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n1, n2, n3, a, b, c;
    cin >> n1 >> n2 >> n3;
    if (n1 > n2 && n1 > n3)
    {
        c = n1;
    }
    else if (n2 > n1 && n2 > n3)
    {
        c = n2;
    }
    else
    {
        c = n3;
    }
    if (n1 < n2 && n1 < n3)
    {
        a = n1;
    }
    else if (n2 < n1 && n2 < n3)
    {
        a = n2;
    }
    else
    {
        a = n3;
    }
    b = n1 + n2 + n3 - a - c;
    char sx;
    cin >> sx;
    if (sx == 'A')
    {
        cout << a << " ";
    }
    else if (sx == 'B')
    {
        cout << b << " ";
    }
    else
    {
        cout << c << " ";
    }
    cin >> sx;
    if (sx == 'A')
    {
        cout << a << " ";
    }
    else if (sx == 'B')
    {
        cout << b << " ";
    }
    else
    {
        cout << c << " ";
    }
    cin >> sx;
    if (sx == 'A')
    {
        cout << a << " ";
    }
    else if (sx == 'B')
    {
        cout << b << " ";
    }
    else
    {
        cout << c << " ";
    }
    return 0;
}