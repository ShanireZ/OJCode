#include <iostream>
using namespace std;
int op[100005], b[100005], ls[100005];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        ls[tmp] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b[i] = ls[b[i]];
    }
    int ed = 0;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] > op[ed])
        {
            op[++ed] = b[i];
        }
        else
        {
            int pos = ed;
            while (b[i] < op[pos] && pos > 0)
            {
                pos--;
            }
            if (pos >= 0 && pos + 1 <= ed)
            {
                op[pos + 1] = b[i];
            }
        }
    }
    cout << ed;
    return 0;
}