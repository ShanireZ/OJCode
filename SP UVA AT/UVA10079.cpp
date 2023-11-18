#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long x;
    cin >> x;
    while (x >= 0)
    {
        cout << x * (x + 1) / 2 + 1 << endl;
        cin >> x;
    }
    return 0;
}