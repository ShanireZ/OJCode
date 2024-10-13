#include <iostream>
#include <map>
using namespace std;
map<string, int> g;
string f[100005][2], nf[100005][2];
int main()
{
    int a, b, c, cnt = 0;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        cin >> f[i][0] >> f[i][1];
    }
    cin >> b;
    for (int i = 1; i <= b; i++)
    {
        cin >> nf[i][0] >> nf[i][1];
    }
    cin >> c;
    for (int i = 1; i <= c; i++)
    {
        string name1, name2, name3;
        cin >> name1 >> name2 >> name3;
        g[name1] = g[name2] = g[name3] = i;
    }
    for (int i = 1; i <= a; i++)
    {
        if (g[f[i][0]] != g[f[i][1]])
        {
            cnt++;
        }
    }
    for (int i = 1; i <= b; i++)
    {
        if (g[nf[i][0]] == g[nf[i][1]])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}