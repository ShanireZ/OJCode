#include <iostream>
using namespace std;
int main()
{
    int cnt = 0, a, b, c;
    cin >> a >> b >> c;
    cnt = (a < 60) + (b < 60) + (c < 60);
    cout << (cnt == 1) ? "1\n" : "0\n";
    return 0;
}
// TAG: 分支 语法