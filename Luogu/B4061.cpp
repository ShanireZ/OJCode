#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b;
    cin >> a >> b;
    cout << a * (1 << b) << endl;
    cout << a / (1 << b) << endl;
    int x = (a >> b) % 2; // a的第b位
    cout << x << endl;
    cout << a - (1 << b) * x << endl;
    cout << a + (1 << b) * !x << endl;
    cout << a + (1 << b) * (x ? -1 : 1) << endl;
    return 0;
}