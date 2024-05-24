#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, k;
    cin >> x >> k;
    x = x / 1000 % k * 1000 + x / 100 % 10 % k * 100 + x / 10 % 10 % k * 10 + x % 10 % k;
    cout << x << endl;
    return 0;
}