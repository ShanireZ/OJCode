#include <algorithm>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int a, b, ans = 1;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        ans = ans * a % 1000;
    }
    cout << setw(3) << setfill('0') << ans << endl;
    return 0;
}