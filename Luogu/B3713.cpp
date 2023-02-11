#include <iostream>
#include <string>
using namespace std;
string pn[15];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> pn[i];
    }
    for (int i = 1; i <= n; i++)
    {
        string kid, path;
        cin >> kid;
        for (int j = 1; j <= m; j++)
        {
            cin >> path;
            if (path == kid + ".zip/" + kid + "/" + pn[j] + "/" + pn[j] + ".cpp")
            {
                cout << "Fusu is happy!\n";
            }
            else
            {
                cout << "Fusu is angry!\n";
            }
        }
    }
    return 0;
}