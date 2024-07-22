#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, y, z, w;
    cin >> x >> y >> z >> w;
    for (int i = 1; i <= 1000; i++)
    {
        if (z * i == x && w * i == y)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}