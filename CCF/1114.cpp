#include <iostream>
#include <cstring>
using namespace std;
int stack[1005];
int order[1005];
int main()
{
    int t, n;
    cin >> t;
    for (int j = 0; j < t; j++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> order[i];
        }
        int top = 0, pos = 0;
        for (int i = 1; i <= n && pos < n;)
        {
            if (order[pos] == i)
            {
                pos++;
                i++;
            }
            else if (order[pos] > i)
            {
                stack[++top] = i;
                i++;
            }
            else
            {
                if (order[pos] == stack[top])
                {
                    top--;
                    pos++;
                }
                else
                {
                    cout << "Impossible";
                    goto endpos;
                }
            }
        }
        cout << "Possible";
    endpos:
        cout << endl;
    }
    return 0;
}