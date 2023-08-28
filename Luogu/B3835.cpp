#include <algorithm>
#include <iostream>
using namespace std;
int m[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int year, month;
    cin >> year >> month;
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        m[2] = 29;
    }
    cout << m[month] << endl;
    return 0;
}
// TAG: 数组 闰年 GESP1