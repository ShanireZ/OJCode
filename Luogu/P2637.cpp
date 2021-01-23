#include <iostream>
#include <algorithm>
using namespace std;
int all[1005];
bool cmp(int a, int b)
{
    return a > b;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> all[i];
    }
    sort(all + 1, all + 1 + m, cmp);
    int maxm = 0, minv = 0;
    for (int i = 1; i <= m; i++)
    {
        int cash = all[i] * i;
        if (cash > maxm)
        {
            maxm = cash;
            minv = all[i];
        }
        else if (cash == maxm && minv > all[i])
        {
            minv = all[i];
        }
    }
    cout << minv << " " << maxm;
    return 0;
}