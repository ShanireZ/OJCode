#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double n, t, m, a, b, c;
    cin >> n >> t >> m >> a >> b >> c;
    double t1 = n / a, t2 = n / b + t, t3 = m / a + (n + m) / c;
    if (t1 < t2 && t1 < t3)
    {
        cout << "MODE I" << endl;
        cout << fixed << setprecision(2) << t1 << endl;
    }
    else if (t2 < t1 && t2 < t3)
    {
        cout << "MODE II" << endl;
        cout << fixed << setprecision(2) << t2 << endl;
    }
    else
    {
        cout << "MODE III" << endl;
        cout << fixed << setprecision(2) << t3 << endl;
    }
    return 0;
}