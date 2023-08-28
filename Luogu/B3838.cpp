#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (c * 60 + d) - (a * 60 + b) << endl;
    return 0;
}
// TAG: 模拟 GESP1