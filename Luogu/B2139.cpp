#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
int prim[100005], all[100005], pos;
string s;
int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 2; i <= 100000; i++)
    {
        if (prim[i] == 0)
        {
            if (i >= m && i <= n)
            {
                pos++;
                all[pos] = i;
            }
            for (int j = i * 2; j <= 100000; j += i)
            {
                prim[j] = 1;
            }
        }
    }
    int ok = 0;
    for (int i = 1; i <= pos; i++)
    {
        s = to_string(all[i]);
        reverse(s.begin(), s.end());
        int fx = stoi(s);
        if (prim[fx] == 0)
        {
            if (ok == 1)
            {
                cout << ",";
            }
            cout << all[i];
            ok = 1;
        }
    }
    if(ok == 0)
    {
        cout << "No";
    }
    return 0;
}