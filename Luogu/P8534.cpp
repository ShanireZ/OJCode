#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, tot = 2;
        long long s;
        cin >> x >> s;
        if (x >= 5)
        {
            tot++;
        }
        if (x >= 3)
        {
            tot++;
        }
        if (s >= 10000000)
        {
            tot++;
        }
        if (s >= 20000000)
        {
            tot++;
        }
        if (s >= 40000000)
        {
            tot++;
        }
        if (s >= 60000000)
        {
            tot++;
        }
        cout << tot << endl;
    }
    return 0;
}