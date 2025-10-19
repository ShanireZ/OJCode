#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int h, m;
    cin >> h >> m;
    int ans = (3 - m % 5 + 5) % 5;
    cout << ans << endl;
    return 0;
}