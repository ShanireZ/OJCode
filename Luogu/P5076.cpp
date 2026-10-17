#include <iostream>
#include <set>
using namespace std;
multiset<int> ms;
int main()
{
    int q;
    cin >> q;
    ms.insert(2147483647);
    ms.insert(-2147483647);
    for (int i = 1; i <= q; i++)
    {
        int t, x;
        cin >> t >> x;
        if (t == 1) //查詢rank
        {
            multiset<int>::iterator it = ms.lower_bound(x);
            int pos = 0;
            while (it != ms.begin())
            {
                pos++;
                it--;
            }
            cout << pos << endl;
        }
        else if (t == 2) //查詢第x個
        {
            multiset<int>::iterator it = ms.begin();
            for (int i = 1; i <= x; i++)
            {
                it++;
            }
            cout << *it << endl;
        }
        else if (t == 3) //求前驅
        {
            multiset<int>::iterator it = ms.lower_bound(x);
            it--;
            cout << *it << endl;
        }
        else if (t == 4) //求後驅
        {
            multiset<int>::iterator it = ms.upper_bound(x);
            cout << *it << endl;
        }
        else //add
        {
            ms.insert(x);
        }
    }
}