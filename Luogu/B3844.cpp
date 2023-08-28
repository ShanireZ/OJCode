#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << char('A' + (i + j) % 26);
        }
        cout << endl;
    }
    return 0;
}
// TAG: 模拟 字符 GESP2