#include <algorithm>
#include <iostream>
using namespace std;
int mx[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int ans = 0, day = 7; // 还有个星期一别看漏了
    for (int i = 1; i <= 12; i++)
    {
        for (int j = 1; j <= mx[i]; j++)
        {
            if (i % 10 == 1 || i / 10 == 1 || j % 10 == 1 || j / 10 == 1 || day == 1)
            {
                ans += 5;
            }
            else
            {
                ans += 1;
            }
            day = (day == 7 ? 1 : day + 1);
        }
    }
    cout << ans << endl;
    return 0;
}