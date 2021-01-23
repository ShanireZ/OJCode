#include <iostream>
using namespace std;
int main()
{
    int n, x, tot = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        int tmp = i;
        while (tmp)
        {
            if (tmp % 10 == x)
            {
                tot++;
            }
            tmp /= 10;
        }
    }
    cout << tot;
    return 0;
}