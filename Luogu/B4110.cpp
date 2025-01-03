#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        char ch;
        cin >> ch;
        cout << (ch == 'J' ? 'O' : (ch == 'O' ? 'I' : 'J'));
    }
    return 0;
}