#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int x, ans = 0;
    cin >> x;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (i * j != x)
            {
                ans += i * j;
            }
        }
    }
    cout << ans << endl;
    return 0;
}