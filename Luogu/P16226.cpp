#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, v, t;
        cin >> l >> v >> t;
        long long p1 = v * t;
        long long p2 = l - p1;
        cout << (p2 - p1 + 1) / 2 << endl;
    }
    return 0;
}