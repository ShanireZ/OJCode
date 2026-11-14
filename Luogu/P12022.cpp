#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int bt[3005][3005], n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            char ch;
            cin >> ch;
            if (ch == 'W')
            {
                bt[i][j] = 1, bt[j][i] = -1;
            }
            else if (ch == 'L')
            {
                bt[i][j] = -1, bt[j][i] = 1;
            }
        }
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        set<int> s;
        for (int i = 1; i <= n; i++)
        {
            if (bt[i][l] == 1 && bt[i][r] == 1)
            {
                s.insert(i);
            }
        }
        cout << s.size() * (n + n - s.size()) << endl;
    }
    return 0;
}