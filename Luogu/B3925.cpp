#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, ex;
    cin >> n >> ex;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    int per = 1;
    while (true)
    {
        int last = (n - 1) * per, ok = 1;
        for (int i = n; i >= 1; i--)
        {
            if (last % (n - 1) != 0)
            {
                ok = 0;
                break;
            }
            last = last + last / (n - 1) + ex;
        }
        if (ok == 0)
        {
            per++;
        }
        else
        {
            cout << last << endl;
            break;
        }
    }
    return 0;
}