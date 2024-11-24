#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int t, a, b, c, d;
    cin >> t >> a >> b >> c >> d;
    if (t == 0)
    {
        cout << a + b << endl;
    }
    else
    {
        cout << max(a - c, 0) + max(b - d, 0) << endl;
    }
    return 0;
}