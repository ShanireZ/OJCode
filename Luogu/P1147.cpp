#include <iostream>
using namespace std;
int main()
{
    int m;
    cin >> m;
    int l = 1;
    int r = 1;
    int total = 1;
    while (r <= m / 2)
    {
        while (total < m)
        {
            r++;
            total += r;
        }
        while (total > m)
        {
            total -= l;
            l++;
        }
        if (total == m)
        {
            cout << l << " " << r << endl;
            total -= l;
            l++;
        }
    }
    return 0;
}