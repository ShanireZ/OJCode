#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << i;
        cout << (a + b > c ? ": true\n" : ": false\n");
    }
    return 0;
}