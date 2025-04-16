#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int l, e;
    cin >> l >> e;
    if (l >= 8 || (l >= 6 && e))
    {
        cout << 3 << endl;
    }
    else if (l >= 3)
    {
        cout << 6 << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    return 0;
}