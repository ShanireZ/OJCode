#include <iostream>
#include <string>
using namespace std;
int n, a, b, tot;
string sa = "/oh", sb = "/hsh";
int main()
{
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s >> s;
        if (s == sa)
        {
            tot += a;
        }
        else if (s == sb)
        {
            tot += b;
        }
    }
    cout << tot << endl;
    return 0;
}