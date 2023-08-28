#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, now = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char('A' + now);
            now = (now + 1) % 26;
        }
        cout << endl;
    }
    return 0;
}
// TAG: 模拟 字符 GESP2