#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long c0 = 0, c1 = 0;
    for (int i = 1; i <= n; i++)
    {
        i % 2 == 1 ? c1 += i : c0 += i;
    }
    cout << c1 << " " << c0 << endl;
    return 0;
}