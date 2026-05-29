#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int s[305], id[305], sc[305], n, m;
vector<int> pre[305];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int t, x;
        cin >> t;
        for (int j = 1; j <= t; j++)
        {
            cin >> x;
            pre[i].push_back(x);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int t, x, trig = 1;
        cin >> t;
        for (int j = 1; j <= t; j++)
        {
            cin >> id[j];
        }
        for (int j = 1; j <= t; j++)
        {
            cin >> sc[j];
        }
        for (int j = 1; j <= t && trig; j++)
        {
            int now = id[j];
            if (s[now] == 1)
            {
                trig = 0;
            }
            for (int pr : pre[now])
            {
                if (s[pr] != 1)
                {
                    trig = 0;
                }
            }
        }
        if (trig == 0)
        {
            cout << "Error" << endl;
        }
        else
        {
            for (int j = 1; j <= t; j++)
            {
                int now = id[j];
                s[now] = (sc[j] >= 60 ? 1 : -1);
                cout << (sc[j] >= 60 ? 'P' : 'F');
            }
            cout << endl;
        }
    }
    return 0;
}