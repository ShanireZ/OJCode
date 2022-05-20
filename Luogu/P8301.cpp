#include <cmath>
#include <iostream>
#include <string>
using namespace std;
string a, b;
int main()
{
    int n, cnta = 0, cntb = 0;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '1')
        {
            cnta++;
        }
        if (b[i] == '1')
        {
            cntb++;
        }
    }
    cout << abs(cnta - cntb) << endl;
    return 0;
}