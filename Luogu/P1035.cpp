#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int k;
    cin >> k;
    double s = 1;
    int n = 1;
    while (s <= k)
    {
        n++;
        s += 1.0 / n;
    }
    cout << n;
    return 0;
}