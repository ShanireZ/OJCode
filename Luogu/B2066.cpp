#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double t = 0;
    for (int i = 1; i <= n; i++)
    {
        double x, y;
        int p;
        cin >> x >> y >> p;
        t += sqrt(x * x + y * y) / 25 + 1.5 * p;
    }
    int x = ceil(t);
    cout << x << endl;
    return 0;
}