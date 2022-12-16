#include <iomanip>
#include <iostream>
using namespace std;
int main() // 找最大值
{
    char opt[5] = {'0', 'W', 'T', 'L'};
    double ans = 1;
    for (int i = 1; i <= 3; i++)
    {
        double maxp = 0, now = 0;
        int p = 0;
        for (int j = 1; j <= 3; j++)
        {
            cin >> now;
            if (now > maxp)
            {
                maxp = now, p = j;
            }
        }
        ans *= maxp;
        cout << opt[p] << " ";
    }
    cout << fixed << setprecision(2) << (ans * 0.65 - 1) * 2;
    return 0;
}