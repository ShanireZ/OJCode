#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
bool prim[2000005];
vector<int> all;
void eula()
{
    for (int i = 2; i <= 2000000; i++)
    {
        if (prim[i] == 0)
        {
            all.push_back(i);
        }
        for (int j = 0; all[j] * i <= 2000000 && j < all.size(); j++)
        {
            prim[all[j] * i] = 1;
            if (i % all[j] == 0)
            {
                break;
            }
        }
    }
}
int main()
{
    eula();
    all.insert(all.begin(), 1);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int p = lower_bound(all.begin(), all.end(), n) - all.begin();
        if (p != all.size() && all[p] == n)
        {
            cout << n << endl;
        }
        else
        {
            cout << all[p - 1] << endl;
        }
    }
    return 0;
}