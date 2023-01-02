#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        x = (x % 2 == 0) ? -1 : log2(x) + 1;
        cout << x << "\n";
    }
    return 0;
}