#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, y;
    cin >> x >> y;
    if (x <= 1 && x >= -1 && y <= 1 && y >= -1)
    {
        cout << "yes\n";
    }
    else
    {
        cout << "no\n";
    }
    return 0;
}