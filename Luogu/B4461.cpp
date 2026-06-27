#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, k, l, c, d, p, v1, p1;
    cin >> n >> k >> l >> c >> d >> p >> v1 >> p1;
    int x = k * l;
    int y = c * d;
    cout << min({x / v1, y, p / p1}) / n << endl;
    return 0;
}