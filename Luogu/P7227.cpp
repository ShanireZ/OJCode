#include <algorithm>
#include <iostream>
using namespace std;
string s = "abcdefghijk";
int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        cout << s << " ";
        next_permutation(s.begin(), s.end());
    }
    return 0;
}