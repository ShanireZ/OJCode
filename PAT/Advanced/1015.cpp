#include <iostream>
using namespace std;
int prim[10000005], trans[100], n, d;
int main()
{
    prim[0] = prim[1] = 1;
    for (int i = 2; i <= 4000; i++)
    {
        if (prim[i] == 0)
        {
            for (int j = 2; i * j <= 10000000; j++)
            {
                prim[i * j] = 1;
            }
        }
    }
    cin >> n;
    while (n > 0)
    {
        cin >> d;
        int ok = prim[n], p = 0;
        while (n)
        {
            trans[p++] = n % d, n /= d;
        }
        for (int i = 0; i < p; i++)
        {
            n = n * d + trans[i];
        }
        ok = max(prim[n], ok);
        cout << (ok ? "No\n" : "Yes\n");
        cin >> n;
    }
    return 0;
}