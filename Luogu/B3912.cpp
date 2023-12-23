#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int ids[5005][5005], p[5005], s[5005], ans[100005];
map<int, long long> tot;
int main()
{
    int k, n;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> p[i];
        for (int j = 1; j <= p[i]; j++)
        {
            cin >> ids[i][j];
        }
        cin >> s[i];
    }
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ans[i];
    }
    for (int i = 1; i <= k; i++)
    {
        int ok = 1;
        for (int j = 2; j <= p[i]; j++)
        {
            if (ans[ids[i][j]] != ans[ids[i][1]])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            tot[ans[ids[i][1]]] += s[i];
        }
    }
    long long maxa = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tot[ans[i]] > tot[maxa])
        {
            maxa = ans[i];
        }
    }
    cout << tot[maxa] << endl
         << maxa << endl;
    return 0;
}