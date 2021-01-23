#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = n / 14; i >= 0; i--)
    {
        for (int j = i; j <= n / 4; j++)
        {
            for (int k = i; k <= n / 3; k++)
            {
                if (7 * i + 4 * j + 3 * k == n)
                {
                    cout << i << " " << j << " " << k;
                    return 0;
                }
            }
        }
    }
    cout << -1;
    return 0;
}