#include <iostream>
#include <string>
using namespace std;
string names[105];
int fs[105];
int main()
{
    int n, pos = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> fs[i] >> names[i];
        if (fs[i] > fs[pos])
        {
            pos = i;
        }
    }
    cout << names[pos] << endl;
    return 0;
}