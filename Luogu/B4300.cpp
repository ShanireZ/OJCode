#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, x, y, day = 0;
    cin >> n >> x >> y;
    while (n > 0)
    {
        day++, n -= x;
        x += y;
    }
    cout << day << endl;
    return 0;
}