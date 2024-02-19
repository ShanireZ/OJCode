#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, n;
    cin >> x >> n;
    x = (x + n) % 7;
    if (x == 0)
    {
        x = 7;
    }
    cout << x << endl;
    return 0;
}