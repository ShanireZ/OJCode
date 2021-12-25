#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, string> q;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string a, b;
        cin >> a >> b;
        q[a] = b;
    }
    for (int i = 1; i <= m; i++)
    {
        string x, a, b, c, d;
        cin >> x >> a >> b >> c >> d;
        if (q[x] == a)
        {
            cout << "A" << endl;
        }
        else if (q[x] == b)
        {
            cout << "B" << endl;
        }
        else if (q[x] == c)
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