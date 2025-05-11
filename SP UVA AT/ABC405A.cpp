#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int r, x;
    cin >> r >> x;
    if (x == 1)
    {
        cout << ((r >= 1600 && r < 3000) ? "Yes" : "No") << endl;
    }
    else
    {
        cout << ((r >= 1200 && r < 2400) ? "Yes" : "No") << endl;
    }
    return 0;
}