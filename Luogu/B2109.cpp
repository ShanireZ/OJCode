#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    char x;
    int cnt = 0;
    while (cin >> x)
    {
        // todo 统计数字字符的个数
        if (x >= '0' && x <= '9')
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}