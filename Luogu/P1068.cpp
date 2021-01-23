#include <iostream>
#include <algorithm>
using namespace std;
int a[5005][2];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 1; j--)
        {
            if ((a[j - 1][1] < a[j][1]) || (a[j - 1][1] == a[j][1] && a[j - 1][0] > a[j][0]))
            {
                swap(a[j - 1], a[j]);
            }
        }
    }
    m = m * 1.5;
    int score = a[m][1], tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i][1] >= score)
        {
            tot++;
        }
        else
        {
            break;
        }
    }
    cout << score << " " << tot << endl;
    for (int i = 1; i <= tot; i++)
    {
        cout << a[i][0] << " " << a[i][1] << endl;
    }
    return 0;
}