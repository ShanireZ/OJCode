#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == b || b == c || a == c)
    {
        cout << "Report" << endl;
        return 0;
    }
    else if (a != d && b != d && c != d)
    {
        d = a + b + c - max({a, b, c}) - min({a, b, c});
    }
    if (a == d)
    {
        cout << "A" << endl;
    }
    else if (b == d)
    {
        cout << "B" << endl;
    }
    else if (c == d)
    {
        cout << "C" << endl;
    }
    return 0;
}