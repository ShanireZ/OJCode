#include <algorithm>
#include <iostream>
using namespace std;
int prim[105];
int main()
{
    prim[0] = prim[1] = 1;
    for (int i = 2; i <= 10; i++)
    {
        if (prim[i] == 0)
        {
            for (int j = i + i; j <= 100; j += i)
            {
                prim[j] = 1;
            }
        }
    }
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        int j = i % 10 * 10 + i / 10;
        if (prim[i] == 0 && prim[j] == 0)
        {
            cout << i << endl;
        }
    }
    return 0;
}