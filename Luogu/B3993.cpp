#include <algorithm>
#include <iostream>
using namespace std;
int m[20] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int month, day;
    cin >> month >> day;
    day++;
    if (day > m[month])
    {
        day = 1, month++;
    }
    if (month == 13)
    {
        month = 1;
    }
    cout << month << " " << day << endl;
    return 0;
}