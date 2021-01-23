#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, tot = 0, max = -1;
    string maxName;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string name;
        int avg, cla, arti, cash = 0;
        char lead, west;
        cin >> name >> avg >> cla >> lead >> west >> arti;
        if (avg > 80 && arti >= 1)
        {
            cash += 8000;
        }
        if (avg > 85 && cla > 80)
        {
            cash += 4000;
        }
        if (avg > 90)
        {
            cash += 2000;
        }
        if (avg > 85 && west == 'Y')
        {
            cash += 1000;
        }
        if (cla > 80 && lead == 'Y')
        {
            cash += 850;
        }
        tot += cash;
        if (cash > max)
        {
            max = cash;
            maxName = name;
        }
    }
    cout << maxName << endl
         << max << endl
         << tot;
    return 0;
}