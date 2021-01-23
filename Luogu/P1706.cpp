#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    int n;
    cin >> n;
    string str;
    string over;
    for (int i = 1; i <= n; i++)
    {
        str += (i + '0');
    }
    over = str;
    do
    {
        for (int i = 0; i < n; i++)
        {
            cout << "    " << str[i];
        }
        cout << endl;
        next_permutation(str.begin(), str.end());
    } while (str != over);
    return 0;
}