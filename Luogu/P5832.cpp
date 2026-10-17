#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    // freopen("whereami.in", "r", stdin);
    // freopen("whereami.out", "w", stdout);
    // ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string way;
    cin >> way;
    for (int i = 1; i <= n; i++) //!長度
    {
        int trig = 1;
        for (int j = 0; j + i <= n; j++) //!從哪開始截取i長度的字串
        {
            string chk = way.substr(j, i);
            if (j + 1 >= n)
            {
                break;
            }
            if (way.find(chk, j + 1) != string::npos) //!出現重複
            {
                trig = 0;
                break;
            }
        }
        if (trig)
        {
            cout << i;
            break;
        }
    }
    return 0;
}