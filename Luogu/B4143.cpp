#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int m1 = (y - x + n) % n, m2 = (x - y + n) % n;
    if (m1 == m2)
    {
        cout << "\"Wonderful\"" << endl;
    }
    else
    {
        cout << (m1 < m2 ? "Clockwise Loop" : "Counter-clockwise Loop") << endl;
    }
    return 0;
}