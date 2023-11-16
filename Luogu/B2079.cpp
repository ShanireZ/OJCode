#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    double e = 1, jc = 1;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        jc = jc * i;
        e += 1 / jc;
    }
    cout << fixed << setprecision(10) << e << endl;
    return 0;
}