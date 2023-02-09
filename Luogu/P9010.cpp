#include <algorithm>
#include <iostream>
using namespace std;
char cows[100005];
int pos[100005], g, h;
int main()
{
    int n;
    cin >> n;
    int fh = n, lh = 1, fg = n, lg = 1, nh = n + 1, ng = n + 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> cows[i];
        cows[i] == 'G' ? fg = min(fg, i) : fh = min(fh, i);
        cows[i] == 'G' ? lg = i : lh = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i];
    }
    for (int i = n; i >= 1; i--)
    {
        if (cows[i] == 'G' && ((i <= fg && pos[i] >= lg) || (i <= nh && pos[i] >= nh)))
        {
            g++, ng = i;
        }
        if (cows[i] == 'H' && ((i <= fh && pos[i] >= lh) || (i <= ng && pos[i] >= ng)))
        {
            h++, nh = i;
        }
    }
    cout << g * h << "\n";
    return 0;
}