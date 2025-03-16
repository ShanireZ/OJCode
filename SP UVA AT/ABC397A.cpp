#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    double x;
    cin >> x;
    if (x >= 38)
    {
        cout << 1 << endl;
    }
    else if (x >= 37.5)
    {
        cout << 2 << endl;
    }
    else
    {
        cout << 3 << endl;
    }
    return 0;
}