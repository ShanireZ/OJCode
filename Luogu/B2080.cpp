#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double e = 1, cf = 1, x;
    int n;
    cin >> x >> n;
    for (int i = 1; i <= n; i++)
    {
        cf = cf * x;
        e += cf;
    }
    cout << fixed << setprecision(2) << e << endl;
    return 0;
}