#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    int x = (k - 1) / m + 1, y = (k - 1) % m + 1;
    int nx = x + y - 1, ny = n - (x - y);
    cout << nx << " " << ny << endl;
    return 0;
}