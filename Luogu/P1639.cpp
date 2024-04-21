#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ans1 = abs(a - b);
    int ans2 = abs(a - x) + abs(b - y);
    int ans3 = abs(a - y) + abs(b - x);
    cout << min(min(ans1, ans2), ans3) << endl;
    return 0;
}