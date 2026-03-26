#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int h1, h2, h3, h4;
    cin >> h1 >> h2 >> h3 >> h4;
    int mn = abs(h1 - h2), h = h2;
    if (mn > abs(h1 - h3) || (mn == abs(h1 - h3) && h3 < h))
    {
        mn = abs(h1 - h3), h = h3;
    }
    if (mn > abs(h1 - h4) || (mn == abs(h1 - h4) && h4 < h))
    {
        mn = abs(h1 - h4), h = h4;
    }
    cout << h << endl;
    return 0;
}