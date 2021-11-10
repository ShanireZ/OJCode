#include <iostream>
using namespace std;
int m[5], c[5];
int main()
{
    for (int i = 1; i <= 3; i++)
    {
        cin >> c[i] >> m[i];
    }
    for (int i = 1; i <= 4; i++)
    {
        int from = i % 3;
        int to = from + 1;
        if (from == 0)
        {
            from = 3;
        }
        int x = min(m[from], c[to] - m[to]);
        m[from] -= x;
        m[to] += x;
    }
    for (int i = 1; i <= 3; i++)
    {
        cout << m[i] << endl;
    }
    return 0;
}