#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, st = 0, ed = -1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x == 1)
        {
            if (st == 0)
            {
                st = i;
            }
            ed = i;
        }
    }
    cout << ed - st + 1 << endl;
    return 0;
}