#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
queue<int> party;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        party.push(i);
    }
    while (party.empty() == false)
    {
        for (int i = 1; i <= m; i++)
        {
            if (i != m)
            {
                party.push(party.front());
            }
            else
            {
                cout << party.front() << " ";
            }
            party.pop();
        }
    }
    return 0;
}