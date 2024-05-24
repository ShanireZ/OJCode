#include <algorithm>
#include <iostream>
using namespace std;
int a[1000005];
int main()
{
    int n, cs = 0, cq = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        int b;
        cin >> b;
        if (a[i] > b)
        {
            cs++;
        }
        else if (a[i] < b)
        {
            cq++;
        }
    }
    cout << cs << " " << cq << endl;
    if (cs > cq)
    {
        cout << 'S' << endl;
    }
    else if (cs < cq)
    {
        cout << 'Q' << endl;
    }
    else
    {
        cout << "Tie" << endl;
    }
    return 0;
}