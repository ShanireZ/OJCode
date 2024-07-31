#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector<int> f[105];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int c, id;
        cin >> c;
        for (int j = 1; j <= c; j++)
        {
            cin >> id;
            f[i].emplace_back(id);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        set<int> s;
        for (int j : f[i])
        {
            s.insert(j);
            for (int k : f[j])
            {
                if (k != i)
                {
                    s.insert(k);
                }
            }
        }
        cout << s.size() << " ";
    }
    return 0;
}