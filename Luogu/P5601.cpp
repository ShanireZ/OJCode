#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string quest[105];
string ans[105];
int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> quest[i] >> ans[i];
    }
    for (int i = 1; i <= q; i++)
    {
        string str, a, b, c, d;
        cin >> str >> a >> b >> c >> d;
        int id;
        for (int j = 1; j <= n; j++)
        {
            if (str == quest[j])
            {
                id = j;
                break;
            }
        }
        if (a == ans[id])
        {
            cout << "A" << endl;
        }
        else if (b == ans[id])
        {
            cout << "B" << endl;
        }
        else if (c == ans[id])
        {
            cout << "C" << endl;
        }
        else
        {
            cout << "D" << endl;
        }
    }
    return 0;
}