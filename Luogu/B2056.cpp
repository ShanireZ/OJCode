#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int tot = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        tot += x;
    }
    cout << tot << " ";
    cout << fixed << setprecision(5) << 1.0 * tot / n << endl;
    return 0;
}