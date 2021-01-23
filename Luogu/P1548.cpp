#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, tot1 = 0, tot2 = 0;
    cin >> n >> m;
    int liml = min(n, m);
    int limr = max(n, m);
    for (int i = 0; i < liml; i++)
    {
        for (int j = 0; j < limr; j++)
        {
            if (i == j)
            {
                tot1 += (n - i) * (m - i);
            }
            else
            {
                tot2 += (n - i) * (m - j);
            }
        }
    }
    cout << tot1 << " " << tot2;
    return 0;
}