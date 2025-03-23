#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << n - (y + x - 1) / x << endl;
    return 0;
}