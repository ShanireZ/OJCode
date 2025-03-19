#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b && a > c)
    {
        cout << "LeftToRight" << endl;
    }
    else if (b > a && b > c)
    {
        cout << "RightToLeft" << endl;
    }
    else
    {
        cout << "None" << endl;
    }
    return 0;
}