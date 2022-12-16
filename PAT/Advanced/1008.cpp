#include <iostream>
using namespace std;
int main() // 模拟电梯上下楼统计耗时
{
    int n;
    cin >> n;
    int now = 0, tot = n * 5;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (now < x)
        {
            tot += (x - now) * 6;
        }
        else
        {
            tot += (now - x) * 4;
        }
        now = x;
    }
    cout << tot;
    return 0;
}