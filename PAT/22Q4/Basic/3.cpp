#include <iostream>
#include <map>
#include <set>
using namespace std;
map<string, int> a;
set<string> s;
int main()
{
    int n, cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string id; // id可能有前导0
        int opt;
        cin >> id >> opt;
        a[id] = opt, s.insert(id);
    }
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (a[*it] == 1)
        {
            cnt++;
            if (cnt > 1)
            {
                cout << " ";
            }
            cout << *it;
        }
    }
    if (cnt == 1)
    {
        cout << "\nDa Ben Zhong is found!\n";
    }
    else
    {
        cout << "\nThere are " << cnt << " suspects.\n";
    }
    return 0;
}