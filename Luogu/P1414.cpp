#include <iostream>
#include <algorithm>
using namespace std;
int t[1000005];
int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        for (int j = 1; j * j <= x; j++)
        {
            if (x % j == 0)
            {
                t[j]++;
                if (j * j != x)
                {
                    t[x / j]++;
                }
            }
        }
    }
    int pos = 1000000;
    for (int i = 1; i <= n; i++)
    {
        for (int j = pos; j >= 1; j--)
        {
            if (t[j] >= i)
            {
                cout << j << endl;
                pos = j;
                break;
            }
        }
    }
    return 0;
}