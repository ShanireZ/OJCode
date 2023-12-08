#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, r, v, m;
    cin >> a >> b >> r >> v >> m;
    cout << r * (a * 4 + b) << " " << v * (6 * a + b) << " " << m * (6 * a + b) << endl;
    return 0;
}