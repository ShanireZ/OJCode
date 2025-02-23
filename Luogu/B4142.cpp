#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long v1, v2, v3, e, m, t;
    cin >> v1 >> v2 >> v3 >> e >> m >> t;
    long long v = v1 * e + v2 * m, ec = v3 * t;
    cout << (v + ec - 1) / ec << endl;
    return 0;
}