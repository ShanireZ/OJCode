#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int a, b, cnt = 0;
    cin >> a >> b;
    for (int num = a; num <= b; num++)
    {
        int ok = 1;
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                ok = 0;
                break;
            }
        }
        cnt += ok;
    }
    cout << cnt << endl;
    return 0;
}
// TAG: 模拟 枚举 GESP2