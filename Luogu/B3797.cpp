#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    cout << "\t";
    for (int i = 1; i <= m; i++)
    {
        cout << i << "%";
        cout << (i == m ? "\n" : "\t");
    }
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t";
        for (int j = 1; j <= m; j++)
        {
            cout << fixed << setprecision(4) << (1 - pow((1 + j / 100.0), -i)) / (j / 100.0);
            cout << (j == m ? "\n" : "\t");
        }
    }
    return 0;
}