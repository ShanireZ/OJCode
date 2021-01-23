#include <iostream>
#include <algorithm>
using namespace std;
int cn[305], tot[305], id[305];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int chn, mat, eng;
        cin >> chn >> mat >> eng;
        cn[i] = chn;
        tot[i] = chn + mat + eng;
        id[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j > 1; j--)
        {
            if ((tot[j - 1] < tot[j]) ||
                (tot[j - 1] == tot[j] && cn[j - 1] < cn[j]) ||
                (tot[j - 1] == tot[j] && cn[j - 1] == cn[j] && id[j - 1] > id[j]))

            {
                swap(tot[j], tot[j - 1]);
                swap(cn[j], cn[j - 1]);
                swap(id[j], id[j - 1]);
            }
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        cout << id[i] << " " << tot[i] << endl;
    }
    return 0;
}