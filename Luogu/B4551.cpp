#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int c1, c2, c3, c4;
    cin >> c1 >> c2 >> c3 >> c4;
    cout << min({c1, c2 + c3, c2 + c4}) << endl;
    return 0;
}