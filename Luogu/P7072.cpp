#include <iostream>
using namespace std;
int s[605];
int main()
{
    int n, w;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        int sz = max(1, i * w / 100);
        int score;
        cin >> score;
        s[score]++;
        int tot = 0, pos = 601;
        while (tot < sz)
        {
            pos--;
            tot += s[pos];
        }
        cout << pos << " ";
    }
    return 0;
}