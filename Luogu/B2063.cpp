#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n;
    double x;
    cin >> x >> n;
    for (int i = 1; i <= n; i++)
    {
        x = x * 1.001;
    }
    cout << fixed << setprecision(4) << x << endl;
    return 0;
}