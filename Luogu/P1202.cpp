#include <iostream>
using namespace std;
int main()
{
    int week[8] = {0};
    int isLeap[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int unLeap[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n;
    cin >> n;
    int pos = 1;
    int year = 1900;
    for (int i = 0; i < n; i++)
    {
        int trig_leap = 0;
        if (((year + i) % 4 == 0 && (year + i) % 100 != 0) || ((year + i) % 400 == 0))
        {
            trig_leap = 1;
        }
        if (trig_leap)
        {
            for (int j = 1; j <= 12; j++)
            {
                for (int k = 1; k <= isLeap[j]; k++)
                {
                    if (pos == 8)
                    {
                        pos = 1;
                    }
                    if (k == 13)
                    {
                        week[pos]++;
                    }
                    pos++;
                }
            }
        }
        else
        {
            for (int j = 1; j <= 12; j++)
            {
                for (int k = 1; k <= unLeap[j]; k++)
                {
                    if (pos == 8)
                    {
                        pos = 1;
                    }
                    if (k == 13)
                    {
                        week[pos]++;
                    }
                    pos++;
                }
            }
        }
    }
    cout << week[6] << " " << week[7];
    for (int i = 1; i < 6; i++)
    {
        cout << " " << week[i];
    }
    return 0;
}