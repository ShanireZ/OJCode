#include <iostream>
#include <cmath>
int check[1000005];
int total[1000005];
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    check[1] = 1;
    for (int i = 2; i <= sqrt(m); i++)
    {
        for (int j = 2; j * i <= m; j++)
        {
            check[i * j] = 1;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        total[i] = total[i - 1];
        if (!check[i])
        {
            total[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        if (r > m || l < 1)
        {
            cout << "Crossing the line" << endl;
        }
        else
        {
            cout << total[r] - total[l - 1] << endl;
        }
    }
    return 0;
}