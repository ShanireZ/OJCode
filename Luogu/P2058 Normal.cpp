#include <iostream>
using namespace std;
int coun[100005];
int all[300005];
int ship[100005];
int times[100005];
int tot;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> times[i] >> ship[i];
        ship[i] += ship[i - 1];
        for (int j = ship[i - 1] + 1; j <= ship[i]; j++)
        {
            cin >> all[j];
            if (coun[all[j]] == 0)
            {
                tot++;
            }
            coun[all[j]]++;
        }
        for (int j = pos; j < i; j++)
        {
            if (times[j] <= times[i] - 86400)
            {
                for (int k = ship[j - 1] + 1; k <= ship[j]; k++)
                {
                    coun[all[k]]--;
                    if (coun[all[k]] == 0)
                    {
                        tot--;
                    }
                }
                pos++;
            }
        }
        cout << tot << endl;
    }
    return 0;
}