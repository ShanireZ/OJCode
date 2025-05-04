#include <algorithm>
#include <iostream>
using namespace std;
string t, u;
int main()
{
    cin >> t >> u;
    for (int i = 0; i <= int(t.size() - u.size()); i++)
    {
        int ok = 1;
        for (int j = 0; j < int(u.size()); j++)
        {
            if (t[i + j] != '?' && t[i + j] != u[j])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}