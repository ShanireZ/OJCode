#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int m, c1 = 0, c0 = 0;
        cin >> m;
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            x == 0 ? c0++ : c1++;
        }
        cout << fixed << setprecision(2) << 1.0 * c0 / (c0 + c1) << endl;
    }
    return 0;
}