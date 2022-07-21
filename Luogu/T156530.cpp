#include <iostream>
#include <sstream>
#include <string>
using namespace std;
string m[15] = {"", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
int d[2][15] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
int main()
{
    string str;
    cin >> str;
    int day = 0, year = 0, month = 0, p = 0;
    for (int i = 1; i <= 12; i++)
    {
        p = str.find(m[i]);
        if (p != string::npos)
        {
            month = i;
            break;
        }
    }
    stringstream ss;
    ss << str.substr(0, p);
    ss >> day;
    ss.clear();
    ss << str.substr(p + 3);
    ss >> year;
    int ans = 0, isr = 0, nyear = 1, nmonth = 1, nday = 1;
    while (true)
    {
        if (nyear == year && nmonth == month && nday == day)
        {
            cout << ans << endl;
            break;
        }
        ans++;
        nday = (nyear == 1582 && nmonth == 10 && nday == 4) ? 15 : nday + 1;
        if (nday > d[isr][nmonth])
        {
            nday = 1, nmonth++;
            if (nmonth > 12)
            {
                nmonth = 1, nyear++;
                isr = ((nyear < 1582 && nyear % 4 == 0) || (nyear % 4 == 0 && nyear % 100 != 0) || nyear % 400 == 0);
            }
        }
    }
    return 0;
}