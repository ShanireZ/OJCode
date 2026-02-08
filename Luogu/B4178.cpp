#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "Draw" << endl;
    }
    else if (a == 1 || (b != 1 && a > b))
    {
        cout << "Awesome" << endl;
    }
    else
    {
        cout << "Brilliant" << endl;
    }
    return 0;
}