#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int ca = 0, ce = 0, cc = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, e, c;
        cin >> a >> e >> c;
        ca += 8 - a, ce += 12 - e, cc += 1 - c;
    }
    cout << min({ca / 8, ce / 12, cc}) << endl;
    return 0;
}