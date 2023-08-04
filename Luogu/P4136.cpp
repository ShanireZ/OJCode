#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n)
    {
        cout << (n % 2 == 1 ? "Bob" : "Alice") << "\n";
        cin >> n;
    }
    return 0;
}