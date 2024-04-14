#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    double tot = 0, v = 7, s, x;
    cin >> s >> x;
    while (tot < s - x)
    {
        tot += v;
        v = v * 0.98;
    }
    if (tot + v > s + x)
    {
        cout << 'n' << endl;
    }
    else
    {
        cout << 'y' << endl;
    }
    return 0;
}