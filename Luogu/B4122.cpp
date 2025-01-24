#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, c, k;
    cin >> x >> c >> k;
    for (int i = 1; i < k; i++)
    {
        x = (x * x + c) % 10000;
    }
    cout << x << endl;
    return 0;
}