#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    double a = 0, b = 0;
    int p = 0, tpa, tpb;
    while (str[p] >= '0' && str[p] <= '9')
    {
        a = a * 10 + (str[p] - '0');
        p++;
    }
    if (str[p] == 'B')
    {
        tpa = 1;
    }
    else if (str[p] == 'K')
    {
        tpa = 2;
    }
    else if (str[p] == 'M')
    {
        tpa = 3;
    }
    else
    {
        tpa = 4;
    }
    while (str[p] != '?')
    {
        p++;
    }
    p++;
    if (str[p] == 'B')
    {
        tpb = 1;
    }
    else if (str[p] == 'K')
    {
        tpb = 2;
    }
    else if (str[p] == 'M')
    {
        tpb = 3;
    }
    else
    {
        tpb = 4;
    }
    b = pow(1024, tpa - tpb) * a;
    cout << fixed << setprecision(6) << b;
    return 0;
}