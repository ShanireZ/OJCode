#include <iostream>
#include <queue>
using namespace std;
struct Ship
{
    int t, k;
};
Ship ship[100005];
int nation[100005];
queue<int> q;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int tot = 0, start = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> ship[i].t >> ship[i].k;
        for (int j = 1; j <= ship[i].k; j++)
        {
            int x;
            cin >> x;
            q.push(x);
            if (nation[x] == 0)
            {
                tot++;
            }
            nation[x]++;
        }
        for (int j = start; j < i; j++)
        {
            if (ship[j].t <= ship[i].t - 86400)
            {
                for (int k = 1; k <= ship[j].k; k++)
                {
                    int x = q.front();
                    q.pop();
                    nation[x]--;
                    if (nation[x] == 0)
                    {
                        tot--;
                    }
                }
                start++;
            }
            else
            {
                break;
            }
        }
        cout << tot << endl;
    }
    return 0;
}