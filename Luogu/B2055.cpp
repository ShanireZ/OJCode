#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double tot = 0;
    for (int i = 1; i <= n; i++)
    {
        double x;
        cin >> x;
        tot += x;
    }
    cout << tot / n << endl;
    return 0;
}