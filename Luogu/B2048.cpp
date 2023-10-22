#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int z, ans = 8;
    char jiaji;
    cin >> z >> jiaji;
    if (jiaji == 'y')
    {
        ans += 5;
    }
    z -= 1000;
    if (z > 0)
    {
        ans += ceil(z / 500.0) * 4;
    }
    cout << ans << endl;
    return 0;
}