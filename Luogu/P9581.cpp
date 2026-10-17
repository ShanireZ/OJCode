#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    cout << min(abs(a) + abs(a - b), abs(b) + abs(b - a)) << endl;
    return 0;
}
// TAG: 枚舉 模擬 貪心