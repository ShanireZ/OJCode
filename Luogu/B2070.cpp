#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double s = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            s += 1.0 / i;
        }
        else
        {
            s -= 1.0 / i;
        }
    }
    cout << fixed << setprecision(4) << s << endl;
    return 0;
}