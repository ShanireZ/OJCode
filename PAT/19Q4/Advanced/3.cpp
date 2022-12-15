#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int nodes[205][205];
vector<vector<int>> p;
int n, m, k;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a][b] = nodes[b][a] = 1;
    }
    cin >> k;
    p.resize(k + 1);
    for (int i = 1; i <= k; i++)
    {
        int l, tmp;
        cin >> l;
        for (int j = 1; j <= l; j++)
        {
            cin >> tmp;
            p[i].push_back(tmp);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int status = 1, id = -1;
        for (int j = 0; j < p[i].size() && status == 1; j++)
        {
            for (int k = 0; k < j; k++)
            {
                if (nodes[p[i][j]][p[i][k]] != 1)
                {
                    status = 3;
                    break;
                }
            }
        }
        if (status == 1)
        {
            for (int inv = 1; inv <= n && status == 1; inv++)
            {
                int trig = 1;
                for (int j = 0; j < p[i].size(); j++)
                {
                    if (nodes[p[i][j]][inv] != 1)
                    {
                        trig = 0;
                        break;
                    }
                }
                if (trig)
                {
                    status = 2;
                    id = inv;
                }
            }
        }
        if (i > 1)
        {
            cout << endl;
        }
        if (status == 1)
        {
            cout << "Area " << i << " is OK.";
        }
        else if (status == 2)
        {
            cout << "Area " << i << " may invite more people, such as " << id << ".";
        }
        else
        {
            cout << "Area " << i << " needs help.";
        }
    }
    return 0;
}