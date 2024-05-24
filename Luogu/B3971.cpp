#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int y;
    cin >> y;
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y % 3200 != 0) || y % 172800 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}