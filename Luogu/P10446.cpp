#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    __int128 aa = a, bb = b, pp = p;
    a = aa * bb % pp;
    cout << a << endl;
    return 0;
}