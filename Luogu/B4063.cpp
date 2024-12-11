#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, j = 0, o = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        x % 2 == 0 ? o++ : j++;
    }
    cout << j << " " << o << endl;
    return 0;
}