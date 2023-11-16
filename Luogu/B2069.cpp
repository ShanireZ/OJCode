#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double tot = 0, p = 1, q = 2;
    for (int i = 1; i <= n; i++)
    {
        tot += q / p;
        double x;
        x = q;
        q = p + q;
        p = x;
    }
    cout << fixed << setprecision(4) << tot << endl;
    return 0;
}