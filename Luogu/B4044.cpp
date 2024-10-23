#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, w, d, fst = 999999;
    cin >> n;
    while (n--)
    {
        cin >> w >> d;
        fst = min(fst, d * 7 + w);
    }
    cout << fst - 6 << endl;
    return 0;
}