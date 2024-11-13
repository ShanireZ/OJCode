#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    cout << min(min(y - q, x - p), min(p, q)) << endl;
    return 0;
}