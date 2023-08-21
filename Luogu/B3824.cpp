#include <iostream>
using namespace std;
int main()
{
    long long a, b, c, d, e, f, k;
    cin >> a >> b >> c >> d >> e >> f >> k;
    cout << max(k / b * a * c, k / e * d * f) << "\n";
    return 0;
}