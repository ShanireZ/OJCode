#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    cout << 10000 * 1.035 * 1.035 * 1.035 * 1.035 * 1.035 << " ";
    cout << 10000 * (1.0 + 0.04 * 5) << endl;
    return 0;
}