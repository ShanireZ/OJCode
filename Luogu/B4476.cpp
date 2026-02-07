#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    // Grey Blue Green Orange Red
    // 0∼99 100∼119 120∼169 170∼229 230∼500
    int a1, a2, a3, a4, a5;
    cin >> a1 >> a2 >> a3 >> a4 >> a5;
    a1 += a2 + a3 + a4 + a5;
    if (a1 < 100)
    {
        cout << "Grey";
    }
    else if (a1 < 120)
    {
        cout << "Blue";
    }
    else if (a1 < 170)
    {
        cout << "Green";
    }
    else if (a1 < 230)
    {
        cout << "Orange";
    }
    else
    {
        cout << "Red";
    }
    return 0;
}