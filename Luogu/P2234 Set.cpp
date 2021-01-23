#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
set<int> sale;
int main()
{
    int tot = 0, n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int s;
        cin >> s;
        if (sale.size() == 0)
        {
            tot += s;
        }
        else
        {
            set<int>::iterator itr = sale.lower_bound(s);
            set<int>::iterator itl = itr;
            if (itl != sale.begin())
            {
                itl--;
            }
            if (itr == sale.end() || s - *itl <= *itr - s)
            {
                tot += abs(s - *itl);
            }
            else
            {
                tot += abs(*itr - s);
            }
        }
        sale.insert(s);
    }
    cout << tot;
    return 0;
}