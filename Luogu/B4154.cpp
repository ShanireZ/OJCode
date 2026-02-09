#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 1)
    {
        cout << a + b << endl;
    }
    else if (c == 2)
    {
        cout << a - b << endl;
    }
    else if (c == 3)
    {
        cout << a * b << endl;
    }
    else
    {
        cout << a / b << endl;
    }
    return 0;
}