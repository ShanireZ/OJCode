#include <algorithm>
#include <iostream>
using namespace std;
int n, k, pos, l, st, len[10000005];
char ch;
int main()
{
    cin >> n >> k;
    while (n--)
    {
        cin >> ch;
        if (ch == '1')
        {
            if (st)
            {
                len[++pos] = l;
                l = 0;
            }
            else
            {
                st = 1;
            }
        }
        else if (st == 1)
        {
            l++;
        }
    }
    if (st == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(len + 1, len + 1 + pos);
    for (int i = 1; i <= pos; i++)
    {
        if (len[i] > k)
        {
            cout << pos - i + 2 << endl;
            return 0;
        }
        else
        {
            k -= len[i];
        }
    }
    cout << 1 << endl;
    return 0;
}