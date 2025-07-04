#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n, k, t;
    cin >> n >> k >> t;
    cout << min(n, k * t) << endl;
    return 0;
}